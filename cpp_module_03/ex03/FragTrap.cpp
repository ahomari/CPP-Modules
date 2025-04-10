/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:29:23 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:43:14 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " is born!" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap (name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " is born!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
    *this = obj;
    std::cout << "FragTrap " << this->name << " Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap has been destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    this->name = obj.name;
    this->hit_points = obj.hit_points;
    this->energy_points = obj.energy_points;
    this->attack_damage = obj.attack_damage;
    std::cout << "FragTrap " << this->name << " Copy constructor called" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap ";
    std::cout << name;
    std::cout << " high fives request!" << std::endl;
}
