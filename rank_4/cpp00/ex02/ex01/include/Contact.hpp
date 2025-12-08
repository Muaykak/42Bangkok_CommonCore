/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:20:10 by srussame          #+#    #+#             */
/*   Updated: 2025/11/21 18:42:11 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:
		bool		setInfo(const std::string &firstname,
						const std::string &lastname,
						const std::string &nickname,
						const std::string &phone_num,
						const std::string &secret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		void		showInfo(void);
		bool		isEmpty(void);
};

#endif