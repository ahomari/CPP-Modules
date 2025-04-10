/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:07:30 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:42:27 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {
    
    std::cout << "--- ClapTrap ---" << std::endl;
    
    ClapTrap clap1("ClapOne");
    clap1.attack("Hamza");
    clap1.takeDamage(clap1.getAttackDamage());
    clap1.beRepaired(3);

    std::cout << "\n--- ScavTrap ---" << std::endl;
    
    ScavTrap scav1("ScavOne");
    scav1.attack("simo");
    scav1.takeDamage(scav1.getAttackDamage());
    scav1.beRepaired(10);
    scav1.guardGate();

    std::cout << "\n--- FragTrap ---" << std::endl;
    
    FragTrap frag1("FragOne");
    frag1.attack("zakaria");
    frag1.takeDamage(frag1.getAttackDamage());
    frag1.beRepaired(15);
    frag1.highFivesGuys();

    return 0;
}