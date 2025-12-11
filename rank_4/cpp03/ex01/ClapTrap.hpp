/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:21 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 14:47:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	protected:
		std::string 	name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDmg;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& obj);
		ClapTrap	&operator=(const ClapTrap &obj);
		virtual ~ClapTrap(); // need virtual destructor
		// Parameter Constructor
		ClapTrap(const std::string &newName);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEP(void) const;
		unsigned int	getATK(void) const;
};

#endif