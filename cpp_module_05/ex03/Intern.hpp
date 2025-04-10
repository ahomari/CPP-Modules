/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:54:59 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/21 17:08:15 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
    public:
        Intern();
        Intern(const Intern& obj);
        ~Intern();
        Intern& operator=(const Intern& obj);
        AForm* makeForm(const std::string& form, const std::string& target);

        class InvalidFormException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};