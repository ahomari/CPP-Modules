/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:07:30 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:38:36 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {
    
    std::cout << "--- ClapTrap ---" << std::endl;
    
    ClapTrap clap1("ClapOne");
    clap1.attack("ahomari");
    clap1.takeDamage(clap1.getAttackDamage());
    clap1.beRepaired(3);

    std::cout << "\n--- ScavTrap ---" << std::endl;
    
    ScavTrap scav1("ScavOne");
    scav1.attack("Enemy");
    scav1.takeDamage(scav1.getAttackDamage());
    scav1.beRepaired(10);
    scav1.guardGate();
    return 0;
}