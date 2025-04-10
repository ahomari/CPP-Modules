/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:56:50 by ahomari           #+#    #+#             */
/*   Updated: 2025/02/01 09:42:28 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> dataFile;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        
        std::map<std::string, double> getMapdata()const;
        void parceInput(const std::string input);
        void loadData(void);
        double getPrice(const std::string& date) const;
};