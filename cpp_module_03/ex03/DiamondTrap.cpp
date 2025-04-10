/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:29:03 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:43:01 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->name = "Default";
    attack_damage = 30;
    std::cout << "DiamondTrap " << name << " is born!" << std::endl;

}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name")
{
    this->name = name;
    attack_damage = 30;
    std::cout << "DiamondTrap " << name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
    *this = obj;
    std::cout << "DiamondTrap " << this->name << " Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap has been destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    ClapTrap::name = obj.ClapTrap::name;
    this->name = obj.name;
    this->hit_points = obj.hit_points;
    this->energy_points = obj.energy_points;
    this->attack_damage = obj.attack_damage;
    std::cout << "DiamondTrap " << this->name << " Copy assignment operator called" << std::endl;
   return *this;

}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name << std::endl;
    std::cout << "ClapTrap name " << ClapTrap::name << std::endl;
}
