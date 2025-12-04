/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:43:54 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 15:21:38 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

// Way to achieve what subject wants is to make the
// use of reference and pointer

class	HumanA
{
	public:
		HumanA(std::string newName, Weapon &newWeapon);
		HumanA(Weapon &newWeapon);
		~HumanA();

		void	attack();

	private:
		// store a reference variable to weapon object
		// Can only initialize with member initializer list
		std::string name;
		// this way when we change the weapon type. the weapon in this
		// class also changes because it is referenced to that Weapon
		Weapon		&weapon;
};

#endif