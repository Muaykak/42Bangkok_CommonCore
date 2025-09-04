/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:20:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/04 13:53:13 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	_firstname = "";
	_lastname = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

Contact::Contact(const std::string &firstname,
	const std::string &lastname,
	const std::string &nickname,
	const std::string &p_number,
	const std::string &secret)
	: _firstname(firstname), _lastname(lastname), _nickname(nickname),
	_phone_number(p_number), _darkest_secret(secret)
{
	std::time(&create_time);
}