/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:32:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/24 20:05:14 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data originalData;
    Data* originalPtr = &originalData;

    uintptr_t serialize = Serializer::serialize(originalPtr);
    Data* deserialize = Serializer::deserialize(serialize);

    
    if (originalPtr == deserialize){
        std::cout << "Pointers are equal" << std::endl;
    } else {
        std::cout << "Pointers are not equal" << std::endl;
    }
    std::cout << originalPtr << std::endl;
    std::cout << deserialize << std::endl;
    std::cout << "--------------originalPtr------------------\n";
    originalPtr->printData();
    std::cout << "-----------------deserialize---------------\n";
    deserialize->printData();
    
}