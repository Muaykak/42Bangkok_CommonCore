/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:43:54 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 14:51:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon		_weapon;
		std::string	_name;
	public:
		HumanA( const Weapon &weapon_type );
		HumanA(  const std::string &human_name, const Weapon &weapon_type );

		void	attack( void );
};

#endif