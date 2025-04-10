/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:37 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/22 11:13:12 by ahomari          ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name)
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

void Bureaucrat::signForm(AForm& form) const
{
    if (form.getSign() == true){

        std::cout << getName() << " Signed " << form.getName() << std::endl;
    } else{
        if (getGrade() > form.getGradeSign()){
            std::cout << getName() << " couldn't sign " << form.getName() << " because Grade is less than GradeSign" << std::endl;
            
        } else{
            form.beSigned(*this);
            std::cout << getName() << " Signed " << form.getName() << std::endl;
        }
    }

}

void Bureaucrat::executeForm(AForm const &form)
{
    try{
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cerr << name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}