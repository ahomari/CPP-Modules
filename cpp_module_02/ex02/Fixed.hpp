/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:01:48 by ahomari           #+#    #+#             */
/*   Updated: 2024/11/28 17:38:14 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_nbr;
        static const int frac;
    public:
        Fixed();
        Fixed(int   fixed_nbr);
        Fixed(float   floating_nbr);
        Fixed(const Fixed& obj);
        ~Fixed();
        
        Fixed& operator++ ();
        Fixed  operator++ (int);
        Fixed& operator-- ();
        Fixed  operator-- (int);
        
        Fixed& operator= (const Fixed& obj);
        
        bool operator> (const Fixed& obj) const ;
        bool operator< (const Fixed& obj) const ;
        bool operator>= (const Fixed& obj) const ;
        bool operator<= (const Fixed& obj) const ;
        bool operator== (const Fixed& obj) const ;
        bool operator!= (const Fixed& obj) const ;
        
        Fixed operator+ (const Fixed& obj) const ;
        Fixed operator- (const Fixed& obj) const ;
        Fixed operator* (const Fixed& obj) const ;
        Fixed operator/ (const Fixed& obj) const ;
        
        float toFloat( void ) const;
        int toInt( void ) const; 
        int getRawBits( void ) const;
        
        static Fixed& min(Fixed& obj1, Fixed& obj2);
        static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
        static Fixed& max(Fixed& obj1, Fixed& obj2);
        static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream &operator<<(std::ostream &out, const Fixed& obj);

#endif