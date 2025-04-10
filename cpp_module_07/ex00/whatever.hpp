/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:46:36 by ahomari           #+#    #+#             */
/*   Updated: 2025/01/04 13:11:11 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &arg1, T &arg2)
{
    T tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
}

template <typename T>
T min(T &arg1, T &arg2)
{
    if (arg1 < arg2)
        return arg1;
    return arg2;
}

template <typename T>
T max(T &arg1, T &arg2)
{
    if (arg1 > arg2)
        return arg1;
    return arg2;
}

