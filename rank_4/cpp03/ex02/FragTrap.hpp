/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:13:27 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 23:23:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(const FragTrap& obj);
		FragTrap&	operator=(const FragTrap& obj);
		~FragTrap();
		FragTrap(const std::string& newName);

		void highFivesGuys(void);
};

#endif