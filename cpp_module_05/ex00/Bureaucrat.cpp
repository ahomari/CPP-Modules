/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:37 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/22 10:57:59 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("ahmed")
{
    grade = 10;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):name(obj.name)
{
    this->grade = obj.grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    this->grade = obj.grade;
    return *this;
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is to High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is to Low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
   out << obj.getName() << " , bureaucrat grade " << obj.getGrade();
    return out;
}
