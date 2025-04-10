/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:27 by ahomari           #+#    #+#             */
/*   Updated: 2025/02/01 09:42:10 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try{
        if (ac != 2){
            throw std::runtime_error("Error: could not open file.");
        }

        BitcoinExchange btc;
        std::string inputFile = av[1];
        if (inputFile.find(".") == std::string::npos || inputFile.substr(inputFile.find("."), inputFile.length()) != ".txt"){
            throw std::runtime_error("Error: Extension is not .txt");
        }
        btc.loadData();
        btc.parceInput(av[1]);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}