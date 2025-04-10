/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:13:56 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/23 16:23:45 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    public:
        const std::string& getType() const;
        void setType(const std::string& type);
        Weapon(const std::string &type);
    
    private:
        std::string type;
};

#endif