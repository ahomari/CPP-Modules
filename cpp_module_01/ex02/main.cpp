/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:15:38 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/23 16:20:55 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* ptr = &str;
    std::string& ref = str;
    
    // -------------------- memory address------------
    
    std::cout << "The memory address of the string is    : " << &str << std::endl;
    std::cout << "The memory address of the stringPTR is : " << ptr << std::endl;
    std::cout << "The memory address of the stringREF is : " << &ref << std::endl;

    //-------------------- value -------------------------

    std::cout << "The value of the string is             : " << str << std::endl;
    std::cout << "The value of the stringPTR is          : " << *ptr << std::endl;
    std::cout << "The value of the stringREF is          : " << ref << std::endl;  
}