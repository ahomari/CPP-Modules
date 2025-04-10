/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:08:18 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/11 10:12:30 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

static int validNumber(std::string num)
{
    int i = 0;
    while (num[i])
    {
        if (!isdigit(num[i]))
            return (0);
        i++;
    }
    return (1);
}

static void printContact(std::string str)
{
    if (str.length() > 10)
        std::cout << std::right << str.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << std::right << str << "|";
}

static std::string setContact(std::string prompt)
{
    std::string line;
    while (line.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit(1);
    }
    return (line);
}

void PhoneBook:: addContact()
{
    std::string line;
    contacts[index].setFirstName(setContact("    First Name :"));
    contacts[index].setLastName(setContact("    Last Name :"));
    contacts[index].setNickname(setContact("    Nickname :"));
    while (true)
    {
        std::cout << "    Phone Number : ";
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit(1);
        if (validNumber(line))
            contacts[index].setPhoneNum(line);
        if (!line.empty() && validNumber(line))
            break;
    }
    contacts[index].setDarkest(setContact("    Darkest Secret :"));
    index++;
    if (index > 7)
        index = 0;
}

void PhoneBook::findContact()
{
    int i = 0;
    int index_contact = 0;
    std::string line;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout  << "|" << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (i < 8 && !contacts[i].getFirstName().empty())
    {
        std::cout << "|" << std::setw(10) << std::right << i + 1 << "|";
        printContact(contacts[i].getFirstName());
        printContact(contacts[i].getLastName());
        printContact(contacts[i].getNickname());
        std::cout << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        i++;
    }
    std::cout << "type index of the contact you want to see" << std::endl;
    std::cout << "index of the contact : ";
    std::getline(std::cin, line);
    if (std::cin.eof())
        exit(1);
    if (line.length() > 1 || line[0] < '1' || line[0] > '8')
    {
        std::cout << "Invalid Index ..." << std::endl;
        return;
    }
    index_contact = index_contact * 10 + (line[0] - 48) - 1;
    if (!contacts[index_contact].getFirstName().empty())
    {
        std::cout << "First Name   : " << contacts[index_contact].getFirstName() << std::endl;
        std::cout << "Last Name    : " << contacts[index_contact].getLastName() << std::endl;
        std::cout << "Nickname     : " << contacts[index_contact].getNickname() << std::endl;
        std::cout << "Phone Number : " << contacts[index_contact].getPhoneNum() << std::endl;
        std::cout << "Darkset      : " << contacts[index_contact].getDarkest() << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
    else
        std::cout << "Index does not exist" << std::endl;
}
