/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:15:20 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/31 19:27:04 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::vector<int>    dataNbr;
    try{
        if (ac == 1){
            throw std::runtime_error("Error: Invalid argument!!");
        }
        loadDataNbr(av, dataNbr);
        PmergeMe merge(dataNbr);
        merge.sortNumbers(dataNbr);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}