/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:01:10 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/23 16:18:01 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
    public:
        //constructor 
        // destructor
        void    setName(std::string name);
        void    announce( void );
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif