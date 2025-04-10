/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:42:07 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/23 15:30:27 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try{
        Bureaucrat bob("bob", 11);
        Form forrrr("forrrr", 10, 20);
        std::cout << forrrr << std::endl;
        bob.signForm(forrrr);

    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}