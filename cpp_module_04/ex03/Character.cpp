/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:02 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 16:38:45 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::garbegeColector(AMateria *addr)
{
    int i = 0;
    while (i < index){
        if (this->garbegeInventory[i] == addr){
            return;
        }
        i++;
    }
    this->garbegeInventory[index] = addr;
    index++;
    if (index >= 100){
        i = 0;
        while (i < 1024){
            delete this->garbegeInventory[i];
            i++;
        }
        index = 0;
    }
}

Character::Character()
{
    this->name = "default";
    index = 0;
    int i = 0;
    while (i < 4){
        this->inventory[i] = NULL;
        i++;
    }
}

Character::Character(const std::string &name)
{
    this->name = name;
    int i = 0;
    while (i < 4){
        this->inventory[i] = NULL;
        i++;
    }
}

Character::Character(const Character &obj)
{
    this->name = obj.name;
    int i = 0;
    while (i < 4){
        if (obj.inventory[i] != NULL){
            this->inventory[i] = obj.inventory[i]->clone();
        }
        else{
            this->inventory[i] = NULL;
        }
        i++;
    }
}

Character::~Character()
{
    int i = 0;
    while (i < index){
        if (this->garbegeInventory[i] != NULL){
            delete this->garbegeInventory[i];
        }
        i++;
    }
    i = 0;
    while (i < 4){
        if (this->inventory[i] != NULL){
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        i++;
    }
}

Character &Character::operator=(const Character &obj)
{
    this->name = obj.name;
    int  i = 0;
    while (i < 4){
        if (this->inventory[i] != NULL){
            delete inventory[i];
        }
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (obj.inventory[i] != NULL){
            this->inventory[i] = obj.inventory[i]->clone();
        }
        else{
            this->inventory[i] = NULL;
        }
        i++;
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    if (!m){
        return;
    }
    int i = 0;
    garbegeColector(m);
    while (i < 4){
        if (this->inventory[i] == NULL){
            this->inventory[i] = m->clone();
            break;
        }
        i++;
    }
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0){
        if (this->inventory[idx] != NULL){
            garbegeColector(this->inventory[idx]);
            this->inventory[idx] = NULL;
        }
    }
    else{
        std::cout << "Invalid index!!" << std::endl;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 4 && idx >= 0){
        if(this->inventory[idx] != NULL){
            this->inventory[idx]->use(target);
        }
    }
    else{
        std::cout << "Invalid Index!!" << std::endl;
    }
}



