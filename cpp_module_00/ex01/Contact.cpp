/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:11:13 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/10 17:52:33 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName()
{
    return firstName;
}

void Contact::setFirstName(std::string firstName)
{
    
    this->firstName = firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

std::string Contact::getNickname()
{
    return nickname;
}

void Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

std::string Contact::getPhoneNum()
{
    return phoneNumber;
}

void Contact::setPhoneNum(std::string phoneNum)
{
    this->phoneNumber = phoneNum;
}

std::string Contact::getDarkest()
{
    return darkest;
}

void Contact::setDarkest(std::string darkest)
{
    this->darkest = darkest;
}
