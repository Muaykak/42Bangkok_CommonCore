/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suttawit <suttawit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:16:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/07 18:04:41 by suttawit         ###   ########.fr       */
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