/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:48:55 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/07 10:48:00 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor called!" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain Copy Constructor called!" << std::endl;
    *this = obj;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called!" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
    std::cout << "Brain Copy Assignment Operator called!" << std::endl;
    int i = 0;
    while (i < 100){
        this->ideas[i] = obj.ideas[i];
        i++;
    }
    return *this;
}
