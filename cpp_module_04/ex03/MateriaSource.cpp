/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:47:27 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/10 16:38:35 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::garbegeColector(AMateria *addr)
{
    int i = 0;
    while (i < index){
        if (this->garbegeMateria[i] == addr){
            return;
        }
        i++;
    }
    this->garbegeMateria[index] = addr;
    index++;
    if (index >= 100){
        i = 0;
        while (i < 100){
            delete this->garbegeMateria[i];
            i++;
        }
        index = 0;
    }
}

MateriaSource::MateriaSource()
{
    int i = 0;
    while (i < 4){
        this->materia[i] = NULL;
        i++;
    }

}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    int i = 0;
    while (i < 4){
        if (obj.materia[i] != NULL){
            this->materia[i] = obj.materia[i]->clone();
        }
        else{
            this->materia[i] = NULL;
        }
        i++;
    }
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while (i < index){
        if (this->garbegeMateria[i] != NULL){
            delete this->garbegeMateria[i];
        }
        i++;
    }
    i = 0;
    while (i < 4){
        if (this->materia[i] != NULL){
            delete this->materia[i];
            this->materia[i] = NULL;
        }
        i++;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    int i = 0;
    while (i < 4){
        if (this->materia[i] != NULL){
            delete this->materia[i];
        }
        i++;
    }
    i = 0;
    while (i < 4){
        if (obj.materia[i] != NULL){
            this->materia[i] = obj.materia[i]->clone();
        }
        else{
            this->materia[i] = NULL;
        }
        i++;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m){
        return ;
    }
    int i = 0;
    garbegeColector(m);
    while (i < 4){
        if (this->materia[i] == NULL){
            this->materia[i] = m->clone();
            break ;
        }
        i++;
    }

}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
    while (i < 4){
        if (this->materia[i] != NULL && this->materia[i]->getType() == type){
            return this->materia[i]->clone();
        }
        i++;
    }
    return NULL;
}
