/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:20:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/04 18:27:38 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

Contact::Contact(const std::string &firstname,
	const std::string &lastname,
	const std::string &nickname,
	const std::string &p_number,
	const std::string &secret)
	: _firstname(firstname), _lastname(lastname), _nickname(nickname),
	_phone_number(p_number), _darkest_secret(secret)
{
	std::time(&_create_time);
}

std::string	Contact::getFirstName(void)
{
	return (_firstname);
}
std::string	Contact::getLastName(void)
{
	return (_lastname);
}
std::string	Contact::getNickName(void)
{
	return (_nickname);
}
std::string	Contact::getPhoneNum(void)
{
	return (_phone_number);
}
std::string	Contact::getSecret(void)
{
	return (_darkest_secret);
}

std::string Contact::getTime(void)
{
	return (std::ctime(&_create_time));
}