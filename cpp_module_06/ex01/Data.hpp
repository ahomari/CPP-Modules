/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:03 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/24 19:58:31 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data
{
    private:
        int i;
        char c;
        double d;
    public:
        Data();
        Data(const Data& obj);
        ~Data();
        Data& operator=(const Data& obj);

        void printData() const;

};