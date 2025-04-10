/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:14:35 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/03 17:30:06 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>


template<typename T, typename Func>
void iter(T* arry, int len, Func func)
{
    for (int i = 0; i < len; i++){
        func(arry[i]);
    }
    
}

void toupperCase(std::string& str)
{
    for(int i = 0; str[i] ; i++){
        str[i] = std::toupper(str[i]);
    }
}

template<typename T>
void printNbr(T& nbr)
{
    std::cout << nbr << " ";
}