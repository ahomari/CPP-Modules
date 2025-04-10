/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:08:24 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/03 15:12:26 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& obj);
        ~ScavTrap();
        
        ScavTrap& operator=(const ScavTrap& obj);
        
        void attack(const std::string& target);
        void guardGate();
};

#endif