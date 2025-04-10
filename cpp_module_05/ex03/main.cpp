/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:42:07 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/22 12:22:52 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    try{
        Intern intern;
        AForm* shrubberyForm = intern.makeForm("shrubbery creation", "home");
        shrubberyForm->executeAction();
        delete shrubberyForm;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    
    try{
        Intern intern;
        AForm* robotomyForm = intern.makeForm("robotomy request", "Alice");
        robotomyForm->executeAction();
        delete robotomyForm;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    
    try{
        Intern intern;
        AForm* pardonForm = intern.makeForm("presidential pardon", "Bob");
        pardonForm->executeAction();
        delete pardonForm;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        Intern intern;
        AForm* invalidForm = intern.makeForm("unknown form", "target");
        invalidForm->executeAction();
        delete invalidForm;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}