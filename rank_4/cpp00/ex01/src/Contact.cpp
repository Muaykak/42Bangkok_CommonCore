/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:20:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/06 01:38:42 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}


std::string	Contact::getFirstName(void) const
{
	return (_firstname);
}
std::string	Contact::getLastName(void) const
{
	return (_lastname);
}
std::string	Contact::getNickName(void) const
{
	return (_nickname);
}

bool	Contact::setInfo(const std::string &firstname,
			const std::string &lastname,
			const std::string &nickname,
			const std::string &phone_num,
			const std::string &secret)
{
	if (firstname.empty() || lastname.empty()
		|| nickname.empty() || phone_num.empty()
		|| secret.empty())
	{
		std::cout << "Each field must not be an empty string" << std::endl;
		return (false);
	}
	this->_firstname = firstname;
	this->_lastname = lastname;
	this-> _nickname = nickname;
	this->_phone_number = phone_num;
	this->_darkest_secret = secret;
	return (true);
}

void	Contact::showInfo(void)
{
	if (this->isEmpty() == true)
		return ;
	std::cout << "First Name: " << _firstname << std::endl;
	std::cout << "Last Name: " << _lastname << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "PhoneNum: " << _phone_number << std::endl;
	std::cout << "darkest secret: " << _darkest_secret << std::endl;
}

bool	Contact::isEmpty(void)
{
	if (_firstname.empty() && _lastname.empty() && _nickname.empty()
		&& _phone_number.empty() && _phone_number.empty() && _darkest_secret.empty())
		return (true);
	return (false);
}