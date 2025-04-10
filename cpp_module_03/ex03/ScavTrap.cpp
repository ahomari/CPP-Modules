/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:08:19 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 10:09:06 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap (name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    *this = obj;
    std::cout << "ScavTrap " << this->name << " Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap has been destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    this->name = obj.name;
    this->hit_points = obj.hit_points;
    this->energy_points = obj.energy_points;
    this->attack_damage = obj.attack_damage;
    std::cout << "ScavTrap " << this->name << " Copy assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (energy_points <= 0){
        std::cout << "ScavTrap ";
        std::cout << name;
        std::cout << " can't attack, no energy points or hit points left!" << std::endl;
        return;
    }
    energy_points--;

    std::cout << "ScavTrap ";
    std::cout << name;
    std::cout << " attacks ";
    std::cout << target;
    std::cout << " causing ";
    std::cout << attack_damage;
    std::cout << " points of damage!" << std::endl;
    
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap ";
    std::cout << name;
    std::cout << " is now in Gate keeper mode" << std::endl;
}
