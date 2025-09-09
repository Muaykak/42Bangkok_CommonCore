/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:07:31 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 14:44:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB{
	private:
		std::string _name;
		Weapon		*_weapon;
	public:
		HumanB();
		HumanB( const std::string &human_name );
		HumanB( const Weapon &weapon_type );
		HumanB(  const std::string &human_name, const Weapon &weapon_type );
		~HumanB();

		void	attack( void );
		void	setWeapon( const Weapon &new_weapon);
};