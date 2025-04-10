/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:15:29 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/23 10:23:08 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
    public:
        void    attack()const;
        void    setWeapon(Weapon &weapon);
        HumanB(std::string name);
        
        
    private:
        std::string name;
        Weapon      *weapon;
};

#endif
