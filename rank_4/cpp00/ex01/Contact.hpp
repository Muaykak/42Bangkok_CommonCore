/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:20:10 by srussame          #+#    #+#             */
/*   Updated: 2025/09/04 18:10:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <ctime>

class	Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		time_t		_create_time;

	public:
		Contact();
		Contact(const std::string &firstname,
			const std::string &lastname,
			const std::string &nickname,
			const std::string &p_number,
			const std::string &secret);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNum(void);
		std::string	getSecret(void);
		std::string	getTime(void);
};

#endif