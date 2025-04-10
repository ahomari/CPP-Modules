/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:08:25 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/21 17:22:18 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        const int           grade_sign;
        const int           grade_execute;
        bool                sign;
    public:
        Form();
        Form(const std::string& name, int grade_sign, int grade_execute);
        Form(const Form& obj);
        ~Form();
        Form& operator=(const Form& obj);

        const std::string& getName() const;
        int getGradeSign() const;
        int getGradeExecute() const; 
        bool getSign() const;
        void beSigned(const Bureaucrat& bureaucrat);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);
