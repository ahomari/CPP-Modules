/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:10:42 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/18 12:13:37 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = 0;
    while (index < 4)
    {
        if (level == levels[index])
            break ;
        index++;
    }
    switch (index)
    {
        case 0:
            std::cout << "=== DEBUG ===" << std::endl;
            debug();
        case 1:
            std::cout << "=== INFO ===" << std::endl;
            info();
        case 2:
            std::cout << "=== WARNING ===" << std::endl;
            warning();
        case 3:
            std::cout << "=== ERROR ===" << std::endl;
            error();
            break ;
        default:
            std::cout << "Unknown level : " << level << std::endl;
            break ;
    }
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup \
    burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t \
    put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
    years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
