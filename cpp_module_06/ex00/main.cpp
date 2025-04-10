/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:38:52 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/24 11:15:48 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    
    if (ac == 2){
        ScalarConverter::convert(av[1]);
    }else {
        std::cerr << "Invalid Argument!!" << std::endl;
    }
    
    return 0;
}