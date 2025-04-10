/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:07:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:42:47 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "Default";
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
    std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    this->name = name;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
    std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj;
    std::cout << "ClapTrap " << this->name << " Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap has been destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    this->name = obj.name;
    this->hit_points = obj.hit_points;
    this->energy_points = obj.energy_points;
    this->attack_damage = obj.attack_damage;
    std::cout << "ClapTrap " << this->name << " Copy assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (energy_points <= 0 || hit_points <= 0){
        std::cout << "ClapTrap ";
        std::cout << name;
        std::cout << " can't attack, no energy points or hit points left!" << std::endl;
        return;
    }
    energy_points--;

    std::cout << "ClapTrap ";
    std::cout << name;
    std::cout << " attacks ";
    std::cout << target;
    std::cout << " causing ";
    std::cout << attack_damage;
    std::cout << " points of damage!" << std::endl;
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points < amount){
        hit_points = 0;
    }else {
        hit_points -= amount;
    }
    std::cout << "ClapTrap ";
    std::cout << name ;
    std::cout << " takes " ;
    std::cout << amount ;
    std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points <= 0 || hit_points <= 0){
        std::cout << "ClapTrap ";
        std::cout << name;
        std::cout << " can't be repaired, no energy points or hit points left!" << std::endl;
        return;
    }
    hit_points += amount;
    energy_points--;
    std::cout << "ClapTrap ";
    std::cout << name;
    std::cout << " is repaired for ";
    std::cout << amount;
    std::cout << " hit points!" << std::endl;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->attack_damage;
}
