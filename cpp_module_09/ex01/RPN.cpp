/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:16:22 by ahomari           #+#    #+#             */
/*   Updated: 2025/02/01 09:43:52 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj){
        this->rpn = obj.rpn;
    }
    return *this;
}

static bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    }
    return false;
}
void RPN::calcule(char *av)
{
    char        c;
    double      nbr1;
    double      nbr2;
    double      res;
    std::string exp = av;
    
    for (size_t i = 0; i < exp.length(); i++){
        c = exp[i];
        if (std::isspace(c)){
            continue;
        }
        else if (std::isdigit(c) && (std::isspace(exp[i + 1]) || exp[i + 1] == '\0')){
            rpn.push(c - '0');
        }
        else if (isOperator(c) && (std::isspace(exp[i + 1]) || exp[i + 1] == '\0')){
            if (rpn.size() < 2){
                throw std::runtime_error("Error: Not enough for this operation");
            }
            nbr2 = rpn.top();
            rpn.pop();
            nbr1 = rpn.top();
            rpn.pop();
            res = operation(nbr1, nbr2, c);
            if (res > std::numeric_limits<double>::max()){
                throw std::runtime_error("Error: number overflow detected!");
            }
            rpn.push(res);
        }
        else{
            throw std::runtime_error("Error");
        }
    }
}

double RPN::operation(double nbr1, double nbr2, char c)
{
    if (c == '+'){
        return nbr1 + nbr2;
    }
    else if (c == '-'){
        return nbr1 - nbr2;
    }
    else if (c == '*'){
        return nbr1 * nbr2;
    }
    else {
        if (nbr2 == 0){
            throw std::runtime_error("Error: Division by zero.");
        }
        return nbr1 / nbr2;   
    }
}

std::stack<double> RPN::getRpn(void) const
{
    return rpn;
}
