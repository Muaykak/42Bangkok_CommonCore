/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:01:53 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 21:01:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(){
	name = "defaultName";
	weapon = NULL;
	std::cout << name << ": default constructor called" << std::endl;
}

HumanB::HumanB(std::string newName){
	name = newName;
	weapon = NULL;
	std::cout << name << ": 1 parameter constructor called" << std::endl;
}

HumanB::HumanB(std::string newName, Weapon &newWeapon){
	name = newName;
	setWeapon(newWeapon);
	std::cout << name << ": 2 parameters constructor called" << std::endl;
}

HumanB::~HumanB(){
	std::cout << name << ": destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	weapon = &newWeapon;
}

void	HumanB::attack(){
	std::cout << name << " attacks with their ";
	if (weapon == NULL)
		std::cout << "bare hands (no weapon).";
	else
		std::cout << weapon->getType();
	std::cout << std::endl;
}