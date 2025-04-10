/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:22:10 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/11 09:56:50 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    std::string line;
    PhoneBook phonebook;
    phonebook.index = 0;
    std::cout << "Welcome to my PhoneBook" << std::endl;
    std::cout << "Command < ADD > Create New Contact" << std::endl;
    std::cout << "Command < SEARCH > Search for a Number in PhoneBook" << std::endl;
    std::cout << "Command < EXIT > Leave PhoneBook" << std::endl;
    while (true)
    {
        std::cout << "Cmd : ";
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit(1);
        if (line == "ADD")
            phonebook.addContact();
        else if (line == "SEARCH")
            phonebook.findContact();
        else if (line == "EXIT")
            exit(0);
        else
            std::cout << "Command not Found !!" << std::endl;
    }
    return (0);
}

