/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:40:35 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/17 08:37:09 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av)
{
    std::string file;
    std::string s1;
    std::string s2;
    if (ac == 4){
        file = std::string(av[1]);
        s1 = std::string(av[2]);
        s2 = std::string(av[3]);
        openFile(file, s1, s2);
    }
    else{
        std::cout << "Invalid  Arg !!" << std::endl;
    }
}
