/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:07:31 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 15:32:13 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB{
	public:
		HumanB(std::string newName, Weapon &newWeapon);
		HumanB(std::string newName);
		HumanB();
		~HumanB();

		void	setWeapon(Weapon &newWeapon);
		void	attack();

	private:
		std::string name;
		// this way, because the class store as a pointer to Weapon.
		// this pointer doesn't need to initialize when constructing the object
		// unlike reference ('&') that need to initialize immediately
		Weapon		*weapon;
};