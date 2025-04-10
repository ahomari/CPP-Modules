/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:01:14 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 13:55:08 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Constructor called!" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    *this = obj;
    std::cout << "Cat Copy Constructor called!" << std::endl;
    
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    type = obj.type;
    std::cout << "Cat Copy Assignment Operator called!" << std::endl;
    return *this;
}

std::string Cat::getType() const
{
    return type;
}

void Cat::makeSound() const
{
    std::cout << "Cat Meow! Meow!" << std::endl;
}
