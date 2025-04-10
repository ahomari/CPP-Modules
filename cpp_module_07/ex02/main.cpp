/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:05:21 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/04 14:04:00 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    
    try {
        Array<int> a;
        std::cout << "Size of a: " << a.size() << std::endl;

        Array<int> b(5);
        std::cout << "Size of b: " << b.size() << std::endl;

        for (unsigned int i = 0; i < b.size(); ++i) {
            b[i] = i * 10;
        }
        for (unsigned int i = 0; i < b.size(); ++i) {
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
        }
        
        a = b;

        a[3] = 0;
        std::cout << "b[3] : " << b[3] << std::endl;
        std::cout << "a[3] : " << a[3] << std::endl;
        

        
        Array<int> c = b;
        c[0] = 100;
        std::cout << "c[0] : " << c[0] << std::endl;
        std::cout << "b[0] : " << b[0] << std::endl;

        std::cout << "Accessing out of bounds: " << b[5] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


