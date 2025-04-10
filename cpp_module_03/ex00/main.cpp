/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:06:53 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:26:35 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void){

    ClapTrap obj("simo");
    ClapTrap obj8("ahomari");
    
    obj.attack("ahomari");
    obj8.takeDamage(obj.getAttackDamage());
    obj8.attack("simo");
    obj.takeDamage(obj8.getAttackDamage());
    obj.beRepaired(2);
}