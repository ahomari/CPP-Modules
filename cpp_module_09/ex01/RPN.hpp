/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:45:16 by ahomari           #+#    #+#             */
/*   Updated: 2025/02/01 09:43:09 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>


class RPN
{
    private:
        std::stack<double> rpn;
    public:
        RPN();
        RPN(const RPN& obj);
        ~RPN();
        RPN& operator=(const RPN& obj);
        void calcule(char *av);
        double operation(double nbr1, double nbr2, char c);
        std::stack<double> getRpn(void) const;
};