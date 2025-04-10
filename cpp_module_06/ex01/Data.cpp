/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:24:55 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/24 19:58:26 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
    i = 10;
    c = 'c';
    d = 5.15;
}

Data::Data(const Data &obj)
{
    *this = obj;
}

Data::~Data()
{
}

Data &Data::operator=(const Data &obj)
{
    this->c = obj.c;
    this->d = obj.d;
    this->i = obj.i;
    return *this;
}

void Data::printData() const
{
    std::cout << "Integer = " << i << std::endl;
    std::cout << "Char = " << c << std::endl;
    std::cout << "Double = " << d << std::endl;
}
