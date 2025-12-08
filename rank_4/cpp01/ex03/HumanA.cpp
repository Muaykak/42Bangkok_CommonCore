/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:02:47 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 15:44:21 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &newWeapon)
			: name(newName), weapon(newWeapon){
	std::cout << name << ": 2 parameters constructor called" << std::endl;
}

HumanA::HumanA(Weapon &newWeapon) : weapon(newWeapon){
	name = "defaultName";
	std::cout << name << ": 1 parameter constructor called" << std::endl;
}

HumanA::~HumanA(){
	std::cout << name << ": destructor called" << std::endl;
}



void HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}