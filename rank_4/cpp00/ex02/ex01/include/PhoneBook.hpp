/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:16:02 by srussame          #+#    #+#             */
/*   Updated: 2025/11/21 18:42:04 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cctype>
# include <iomanip>

class	PhoneBook
{
	private:
		Contact _contact_list[8];
		int		_oldest_index;
		int		_newest_index;

	public:
		PhoneBook();
		int		addContact(const std::string &firstname,
					const std::string &lastname,
					const std::string &nickname,
					const std::string &phone_num,
					const std::string &secret);
		void	displayBook(void);
		bool	showContact(int index);
		bool	isEmpty(void);
};

#endif