/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:45:02 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/23 16:17:00 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void){
    int n = 10;
    int i = 0;
    Zombie* zombie = zombieHorde(n, "ahmed");
    if (zombie == NULL){
        std::cerr << "The number is negative" << std::endl;
        return 1;
    }
    while (i < n){
        zombie[i].announce();
        i++;
    }
    delete[] zombie;
    return 0;
}