/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:16:17 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 13:55:21 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Constructor called!" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    *this = obj;
    std::cout << "Dog Copy Constructor called!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    type = obj.type;
    std::cout << "Dog Copy Assignment Operator called!" << std::endl;
    return *this;
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout << "Dog Woof! Woof!" << std::endl;
}
