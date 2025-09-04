/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:20:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/04 23:30:12 by srussame         ###   ########.fr       */
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

static bool	isEmptyOrWhitespace(const std::string &str)
{
	if (str.empty() == true)
		return (true);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != '\t'
		&& str[i] != '\v'
		&& str[i] != '\n'
		&& str[i] != '\f'
		&& str[i] != '\r'
		&& str[i] != ' ')
			return (false);
	}
	return (true);
}

static void	ftStrTrim(std::string &str)
{
	size_t	first = str.find_first_not_of("\t\v\n\f\r ");
	size_t	last = str.find_last_not_of("\t\v\n\f\r ");
	str = str.substr(first, last - first + 1);
}

bool	Contact::setInfo(const std::string &firstname,
			const std::string &lastname,
			const std::string &nickname,
			const std::string &phone_num,
			const std::string &secret)
{
	if (isEmptyOrWhitespace(firstname)
	|| isEmptyOrWhitespace(lastname)
	|| isEmptyOrWhitespace(nickname)
	|| isEmptyOrWhitespace(phone_num)
	|| isEmptyOrWhitespace(secret))
	{
		std::cout << "Each field must not be an empty string,\
or contained only whitespaces" << std::endl;
		return (false);
	}
	this->_firstname = firstname;
	this->_lastname = lastname;
	this-> _nickname = nickname;
	this->_phone_number = phone_num;
	this->_darkest_secret = secret;
	ftStrTrim(this->_firstname);
	ftStrTrim(this->_lastname);
	ftStrTrim(this->_nickname);
	ftStrTrim(this->_phone_number);
	ftStrTrim(this->_darkest_secret);
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