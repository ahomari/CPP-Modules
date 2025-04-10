/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:29:29 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/04 12:43:19 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public :
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& obj);
        ~FragTrap();

        FragTrap& operator=(const FragTrap& obj);

        void highFivesGuys(void);

};

#endif