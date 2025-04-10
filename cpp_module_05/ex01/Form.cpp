/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:21:32 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/13 18:12:56 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Form"), grade_sign(4), grade_execute(8)
{
    sign = false;
    if (grade_sign < 1 || grade_execute < 1){
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150){
        throw GradeTooLowException();
    }
}

Form::Form(const std::string &name, int grade_sign, int grade_execute): name(name), grade_sign(grade_sign), grade_execute(grade_execute)
{
    sign = false;
    if (grade_sign < 1 || grade_execute < 1){
        throw GradeTooHighException();
    }
    if (grade_sign > 150 || grade_execute > 150){
        throw GradeTooLowException();
    }
}

Form::Form(const Form &obj): name(obj.name), grade_sign(obj.grade_sign), grade_execute(obj.grade_execute)
{
    this->sign = obj.sign;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &obj)
{
    this->sign = obj.sign;
    return *this;
}

const std::string &Form::getName() const
{
   return name;
}

int Form::getGradeSign() const
{
    return grade_sign;
}

int Form::getGradeExecute() const
{
    return grade_execute;
}

bool Form::getSign() const
{
    return sign;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getGradeSign()){
        this->sign = true;
    } else{
        throw GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is to High!";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is to Low!";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << obj.getName() << " grade required to sign " << obj.getGradeSign() << " grade required to execute " << obj.getGradeExecute() << " signed " << obj.getSign();
    return out;
}
