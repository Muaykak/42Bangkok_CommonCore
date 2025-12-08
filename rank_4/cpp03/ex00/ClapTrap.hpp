/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:21 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 23:07:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
		std::string 	name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDmg;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& obj);
		ClapTrap	&operator=(const ClapTrap &obj);
		~ClapTrap();
		// Parameter Constructor
		ClapTrap(const std::string &newName);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif