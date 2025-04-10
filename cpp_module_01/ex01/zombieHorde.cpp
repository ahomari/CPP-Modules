/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:21:24 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/17 09:59:13 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N > 0) {
        int i = 0;
        Zombie* zombie = new Zombie[N];
        while (i < N){
            zombie[i].setName(name);
            i++;
        }
        return zombie;
    }
    else {
        return NULL;
    }
}