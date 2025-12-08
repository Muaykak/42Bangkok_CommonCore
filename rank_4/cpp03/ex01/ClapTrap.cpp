/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:24 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 23:09:27 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap defaultName" << ": Default constructor called" << std::endl;
	name = "defaultName";
	hitPoint = 10;
	energyPoint = 10;
	attackDmg = 0;
}
// Copy constructor
ClapTrap::ClapTrap( const ClapTrap &obj){
	std::cout << "ClapTrap " << obj.name << ": Copy constructor operator called" << std::endl;
	operator=(obj);
}
// Copy assignment operator
ClapTrap	&ClapTrap::operator=(const ClapTrap &obj){
	std::cout << "ClapTrap " << obj.name << ": Copy assignment operator called" << std::endl;
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDmg = obj.attackDmg;
	return (*this);
}
//Destructor
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << ": Destructor called" << std::endl;
}
// Parameter constructor
ClapTrap::ClapTrap(const std::string &newName){
	std::cout << "ClapTrap " << newName << ": Parameter constructor called" << std::endl;
	name = newName;
	hitPoint = 10;
	energyPoint = 10;
	attackDmg = 0;
}

void	ClapTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0){
		std::cout << "ClapTrap " << name << " attacks " << target << " causing "
		<< attackDmg << " points of damage!" << std::endl;
		energyPoint--;
	}
	else {
		if (hitPoint > 0)
			std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
		else
			std::cout << "ClapTrap " << name << " has no hitpoints and cannot attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	hitPoint = hitPoint <= amount ? 0 : hitPoint - amount;
	std::cout << "ClapTrap " << name << " takes "
	<< amount << " damages.(HP remaining: " << hitPoint << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (hitPoint > 0 && energyPoint > 0){
		hitPoint += amount;
		std::cout << "ClapTrap " << name << " repairs itself by " << amount
		<< " hitpoints. (HP remaining: " << hitPoint << ")" << std::endl;
	}
	else {
		if (hitPoint > 0)
			std::cout << "ClapTrap " << name << " has no energy to repair itself." << std::endl;
		else
			std::cout << "ClapTrap " << name << " has no hitpoints and cannot repair itself." << std::endl;
	}
}