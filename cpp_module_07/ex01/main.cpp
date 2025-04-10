/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:05:21 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/04 13:16:32 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {

    
    std::cout << "---------------test INT-----------------------\n";
    
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Print integers: ";
    iter(numbers, 5, printNbr<const int>);
    std::cout << "\n";
    
    std::cout << "----------------test STRING----------------------\n";
    
    std::string words[] = {"hello", "world"};
    iter(words, 2, toupperCase);
    std::cout << "Uppercase strings: ";
    for (int i = 0; i < 2; i++) {
        std::cout << words[i] << " ";
    }
    std::cout << "\n";
    return 0;
}