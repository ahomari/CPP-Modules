/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:33:26 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/23 11:55:51 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &obj)
{
    (void)obj;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return *this;
}

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}
static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    
    AForm* (*createForm[])(const std::string&) = {
        createRobotomy,
        createPresidential,
        createShrubbery,
    };
    std::string formName[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    for (int i = 0; i < 3; i++){
        if (form == formName[i]){
            std::cout << "Intern creates " << form <<  " form." << std::endl;
            return createForm[i](target);
        }
    }
    throw InvalidFormException();
}

const char *Intern::InvalidFormException::what() const throw()
{
    return "Form does not exist.";
}
