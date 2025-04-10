/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:17:05 by ahomari           #+#    #+#             */
/*   Updated: 2024/12/21 09:40:08 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
    *this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    AForm::operator=(obj);
    this->target = obj.target;
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "BRRRRRRRRRRRRRRRRRRRRZZZZZZZTTTTTTTT" << std::endl;
    srand((unsigned int)time(0));
    if (rand() % 2){
        std::cout << target << " has been robotomized successfully" << std::endl;
    } else{
        std::cout << target << " has been robotomized failed" << std::endl;
    }

}
