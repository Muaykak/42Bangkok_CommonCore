/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:50:51 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 13:47:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap{
	private:
		bool	guardStatus;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& obj);
		ScavTrap&	operator=(const ScavTrap& obj);
		~ScavTrap();
		ScavTrap(const std::string& newName);

		void	attack(const std::string& target);
		void	guardGate();
		bool	getGuardStatus(void) const;
};

#endif