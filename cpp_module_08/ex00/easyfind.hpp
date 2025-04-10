/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:55:29 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/09 11:11:10 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

template<typename T>
typename T::iterator easyfind(T& array, int nbr)
{
    typename T::iterator it = std::find(array.begin(), array.end(), nbr);
    if (it == array.end()){
        throw std::runtime_error("This number is not available");
    }
    return it;
}