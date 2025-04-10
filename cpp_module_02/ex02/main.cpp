/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:43:30 by ahomari           #+#    #+#             */
/*   Updated: 2024/11/28 15:56:24 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"



int main( void ) {
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::min( a, b ) << std::endl;
    }
    {
        Fixed a(10.5f);
        Fixed b(10.4f);
        
        std::cout << "a > b: " << (a > b) << std::endl;
        std::cout << "a < b: " << (a < b) << std::endl;
        std::cout << "a >= b: " << (a >= b) << std::endl;
        std::cout << "a <= b: " << (a <= b) << std::endl;
        std::cout << "a == b: " << (a == b) << std::endl;
        std::cout << "a != b: " << (a != b) << std::endl;
    }
    return 0;
}