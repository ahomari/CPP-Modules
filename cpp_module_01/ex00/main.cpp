/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:45:02 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/28 11:50:26 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    randomChump("ahmed");
    Zombie* zombie1 = newZombie("simo");
    zombie1->announce();
    delete zombie1;
}