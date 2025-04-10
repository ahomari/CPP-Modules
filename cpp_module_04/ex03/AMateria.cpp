/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:31:03 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/09 23:23:46 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "Default";
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &obj)
{
    this->type = obj.type;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &obj)
{
    this->type = obj.type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria " << target.getName() << std::endl;
}
