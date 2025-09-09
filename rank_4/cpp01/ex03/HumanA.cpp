/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:02:47 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 14:51:07 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( const Weapon &weapon_type ){
	this->_name = "HumanA_defaultName";
	this->_weapon.setType(weapon_type.getType());
}

HumanA::HumanA(  const std::string &human_name, const Weapon &weapon_type ){
	this->_name = human_name;
	this->_weapon.setType(weapon_type.getType());
}

void	HumanA::attack( void ){
	std::cout << this->_name << " attack with their " << this->_weapon.getType() << std::endl;
}