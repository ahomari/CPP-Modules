/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:08:25 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/20 12:50:38 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        const int           grade_sign;
        const int           grade_execute;
        bool                sign;
    public:
        AForm();
        AForm(const std::string& name, int grade_sign, int grade_execute);
        AForm(const AForm& obj);
        virtual ~AForm();
        AForm& operator=(const AForm& obj);

        const std::string& getName() const;
        int getGradeSign() const;
        int getGradeExecute() const; 
        bool getSign() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;
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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);
