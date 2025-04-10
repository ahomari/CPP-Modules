/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:07:30 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:43:24 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    
    std::cout << "--- DiamondTrap ---" << std::endl;
    
    DiamondTrap diamond1("Sparkle");
    DiamondTrap diamond2("ahomari");
    diamond2 = diamond1;
    diamond2.attack("Sparkle");
    diamond1.attack("ahomari");
    diamond1.takeDamage(diamond2.getAttackDamage());
    diamond1.beRepaired(20);
    diamond1.guardGate();
    diamond1.highFivesGuys();
    diamond1.whoAmI();
    
    return 0;
}