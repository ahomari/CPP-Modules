/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:31:05 by ahomari           #+#    #+#             */
/*   Updated: 2024/10/11 10:31:08 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		std::string getFirstName();
		void setFirstName(std::string firstName);
		std::string getLastName();
		void setLastName(std::string lastName);
		std::string getNickname();
		void setNickname(std::string nickname);
		std::string getPhoneNum();
		void setPhoneNum(std::string phoneNum);
		std::string getDarkest();
		void setDarkest(std::string darkest);

    private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkest;
};

#endif