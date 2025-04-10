/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:04:31 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/28 10:04:42 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Function.hpp"

int main()
{
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr); 
    delete ptr;
    return 0;
}