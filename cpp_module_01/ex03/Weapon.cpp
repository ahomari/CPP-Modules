/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:14:21 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/23 16:25:25 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const{
    return type;
}

void Weapon::setType(const std::string& type){
    this->type = type;
}

Weapon::Weapon(const std::string &type)
{
    this->type = type;
}
