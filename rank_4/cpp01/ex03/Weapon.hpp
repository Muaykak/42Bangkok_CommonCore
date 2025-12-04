/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:34:31 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 14:21:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	public:
		Weapon();
		Weapon(std::string newType);
		~Weapon();

		const std::string	&getType();
		void				setType(std::string newType);

	private:
		std::string	type;
};

#endif