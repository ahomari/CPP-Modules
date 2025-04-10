/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:42:07 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/22 11:06:47 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("shrubbery");
        RobotomyRequestForm robotomy("robotomy");
        PresidentialPardonForm pardon("pardon");
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        bob.signForm(pardon);
        bob.executeForm(pardon);
    } 
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}