/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:57:46 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 13:46:09 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat Constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj)
{
    *this = obj;
    std::cout << "WrongCat Copy Constructor called!" << std::endl;
    
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    type = obj.type;
    std::cout << "WrongCat Copy Assignment Operator called!" << std::endl;
    return *this;
}

std::string WrongCat::getType() const
{
    return type;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Meow! Meow!" << std::endl;
}