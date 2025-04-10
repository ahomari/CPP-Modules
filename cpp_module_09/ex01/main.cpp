/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:47:05 by ahomari           #+#    #+#             */
/*   Updated: 2025/02/01 09:58:43 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    try{
        RPN         rpn;
        if (ac != 2){
            throw std::runtime_error("Error: Invalid argument!!");
        }
        rpn.calcule(av[1]);
        if (rpn.getRpn().size() != 1){
            throw std::runtime_error("Error");
        }
        std::cout << rpn.getRpn().top() << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}