/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:39:02 by ahomari           #+#    #+#             */
/*   Updated: 2024/11/28 14:42:51 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int nbr;
        static const int frac;
    public:
        Fixed();
        Fixed(const Fixed& obj);
        ~Fixed();
        
        Fixed& operator= (const Fixed& obj);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif