/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:47:48 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 13:42:49 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal Constructor called!" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    *this = obj;
    std::cout << "Animal Copy Constructor called!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called!" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    type = obj.type;
    std::cout << "Animal Copy Assignment Operator called!" << std::endl;
    return *this;
}
