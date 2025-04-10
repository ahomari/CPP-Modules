/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:43:06 by ahomari           #+#    #+#             */
/*   Updated: 2024/11/28 17:38:02 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_nbr = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

int Fixed::getRawBits(void) const
{
    return fixed_nbr;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_nbr = obj.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(int fixed_nbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_nbr = fixed_nbr * (1 << frac);
}

Fixed::Fixed(float floating_nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_nbr = roundf(floating_nbr * (1 << frac));
}

float Fixed::toFloat(void) const
{
    return (float) fixed_nbr / (1 << frac);
}

int Fixed::toInt(void) const
{
    return (fixed_nbr / (1 << frac));
}

std::ostream &operator<<(std::ostream &out, const Fixed& obj)
{
    out << obj.toFloat();
    return out;
}

