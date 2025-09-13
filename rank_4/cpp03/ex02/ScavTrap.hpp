/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:20:52 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 13:25:07 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		bool	_gate_keeper_mode;
	public:
		ScavTrap();
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &other );
		ScavTrap	&operator=( const ScavTrap &other );
		~ScavTrap();

		void	attack( const std::string &target );
		void	guardGate();
};

#endif