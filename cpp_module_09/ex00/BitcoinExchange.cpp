/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:09:59 by ahomari           #+#    #+#             */
/*   Updated: 2025/02/01 11:07:10 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}

BitcoinExchange::~BitcoinExchange()
{
    dataFile.clear();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj){
        dataFile = obj.dataFile;
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::getMapdata() const
{
    return dataFile;
}

static std::string strtrim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        start++;
    }
    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1])) {
        end--;
    }
    return str.substr(start, end - start);
}

static bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

static bool isValidDate(const std::string& date)
{
    int year, month, day;
    std::string tmp;
    int dayMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5, 7).c_str());
    day = atoi(date.substr(8, date.length()).c_str());
    if (isLeapYear(year)){
        dayMonth[1] = 29;
    }
    if (year >= 2009 && month >= 1 && month <= 12){
        if (day >= 1 && day <= dayMonth[month - 1]){
            return true;
        }
    }
    return false;
}

void BitcoinExchange::parceInput(const std::string input)
{
    std::ifstream inputFile;
    std::string line;
    std::string date;
    std::string value;
    double amount;
    char *res;
    bool firstLine = false;
    
    inputFile.open(input);
    if (!inputFile.is_open()){
        throw std::runtime_error("File could not be opened!");
    }
    if (inputFile.peek() == EOF){
        throw std::runtime_error("Error: Input File is empty!");
    }
    while (std::getline(inputFile, line))
    {
        date = strtrim(line.substr(0, line.find('|')));
        value = strtrim(line.substr(line.find('|') + 1, line.length() - line.find('|')));
        amount = strtod(value.c_str(), &res);
        if (firstLine == false){
            if (date != "date" || value != "value"){
                throw std::runtime_error("Error: format file Input");
            }
            firstLine = true;
        }
        else if (!isValidDate(date)){
            std::cerr << "Error: bad input => " << date << std::endl;
        }
        else if ( amount < 0 || amount > 1000 || res[0] || value.empty()){
            if (amount < 0){
                std::cout << "Error: not a positive number." << std::endl;
            }
            else if (amount > 1000){
                std::cout << "Error: too large a number." << std::endl;
            }
            else {
                std::cout << "Error: There is an error in value." << std::endl;
            }
        }
        else{
            try{
                std::cout << date << " => " << amount << " = " << amount * getPrice(date) << std::endl;
            } catch (const std::exception& e){
                std::cerr << e.what() << std::endl;
            }
        }
        
    }
    inputFile.close();
}

void BitcoinExchange::loadData(void)
{
    std::ifstream dataFile;
    std::string line;
    std::string date;
    std::string exchange;
    double      value;

    dataFile.open("data.csv");
    if (!dataFile.is_open()){
        throw std::runtime_error("Error: File could not be opened!");
    }
    if (dataFile.peek() == EOF){
        throw std::runtime_error("Error: Data File is empty!");
    }
    while (std::getline(dataFile, line))
    {
        date = line.substr(0, line.find(','));
        exchange = line.substr(line.find(',') + 1, line.length() - line.find(','));
        value = atof(exchange.c_str());
        if (date != "date"){
            this->dataFile[date] = value;
        }
    }
    dataFile.close();
}

double BitcoinExchange::getPrice(const std::string &date) const
{
    std::map<std::string, double> tmp = getMapdata();
    std::map<std::string, double>::iterator it = tmp.lower_bound(date);
    if (it == tmp.end() || it->first != date){
        if (it == tmp.begin()){
            throw std::runtime_error("Error: date not fond!!");
        }
        it--;
    }
    return it->second;
}
