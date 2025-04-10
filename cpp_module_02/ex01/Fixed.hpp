/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:42:38 by ahomari           #+#    #+#             */
/*   Updated: 2024/11/28 17:37:44 by ahomari          ###   ########.fr       */
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
        
        Fixed& operator= (const Fixed& obj);
        
        int getRawBits( void ) const;
        float toFloat( void ) const;
        int toInt( void ) const; 
};

std::ostream &operator<<(std::ostream &out, const Fixed& obj);

#endif