/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:43:16 by ahomari           #+#    #+#             */
/*   Updated: 2024/11/28 17:38:33 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"


const int Fixed::frac = 8;

Fixed::Fixed()
{
    this->fixed_nbr = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    this->fixed_nbr = obj.fixed_nbr;
    return *this;
}

Fixed::~Fixed()
{ 
}
Fixed::Fixed(int fixed_nbr)
{
    this->fixed_nbr = fixed_nbr * (1 << frac);
}

Fixed::Fixed(float floating_nbr)
{
    this->fixed_nbr = roundf(floating_nbr * (1 << frac));
}

int Fixed::getRawBits(void) const
{
    return fixed_nbr;
}


float Fixed::toFloat(void) const
{
    return (float)fixed_nbr / (1 << frac);
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

Fixed &Fixed::operator++()
{
    fixed_nbr++;
    return *this;
}

Fixed &Fixed::operator--()
{
    fixed_nbr--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->fixed_nbr++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->fixed_nbr--;
    return tmp;
}

bool Fixed::operator>(const Fixed &obj) const
{   
    return this->fixed_nbr > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
    return this->fixed_nbr < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return this->fixed_nbr >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return this->fixed_nbr <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
    return this->fixed_nbr == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return this->fixed_nbr != obj.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    return Fixed(this->toFloat() + obj.toFloat()); 
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return  Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    return  Fixed(this->toFloat() / obj.toFloat());
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
    if (obj1.fixed_nbr < obj2.fixed_nbr)
        return obj1;
    return obj2;
}
Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
    if (obj1.fixed_nbr > obj2.fixed_nbr)
        return obj1;
    return obj2;
}
const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
    if (obj1.fixed_nbr < obj2.fixed_nbr)
        return obj1;
    return obj2;
}
const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
    if (obj1.fixed_nbr > obj2.fixed_nbr)
        return obj1;
    return obj2;
}
