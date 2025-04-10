/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:21:32 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/17 15:19:13 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "AForm.hpp"

AForm::AForm(): name("AForm"), grade_sign(4), grade_execute(8)
{
    sign = false;
    if (grade_sign < 1 || grade_execute < 1){
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150){
        throw GradeTooLowException();
    }
}

AForm::AForm(const std::string &name, int grade_sign, int grade_execute): name(name), grade_sign(grade_sign), grade_execute(grade_execute)
{
    sign = false;
    if (grade_sign < 1 || grade_execute < 1){
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150){
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm &obj): name(obj.name), grade_sign(obj.grade_sign), grade_execute(obj.grade_execute)
{
    this->sign = obj.sign;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &obj)
{
    this->sign = obj.sign;
    return *this;
}

const std::string &AForm::getName() const
{
   return name;
}

int AForm::getGradeSign() const
{
    return grade_sign;
}

int AForm::getGradeExecute() const
{
    return grade_execute;
}

bool AForm::getSign() const
{
    return sign;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getGradeSign()){
        this->sign = true;
    } else{
        throw GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is to High!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is to Low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed !";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << obj.getName() << " grade required to sign " << obj.getGradeSign() << " grade required to execute " << obj.getGradeExecute() << " signed " << obj.getSign();
    return out;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (getSign() == false){
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeExecute()){
        throw GradeTooLowException();
    }
    executeAction();
}
