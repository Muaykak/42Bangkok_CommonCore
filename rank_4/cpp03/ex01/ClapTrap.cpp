/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:24 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 16:19:38 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap Default constructor called" << std::endl;
	name = "defaultName";
	hitPoint = 10;
	energyPoint = 10;
	attackDmg = 0;
}
// Copy constructor
ClapTrap::ClapTrap( const ClapTrap &obj){
	std::cout << "ClapTrap Copy constructor operator called" << std::endl;
	if (this != &obj){
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDmg = obj.attackDmg;
	}
}
// Copy assignment operator
ClapTrap	&ClapTrap::operator=(const ClapTrap &obj){
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &obj){
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDmg = obj.attackDmg;
	}
	return (*this);
}
//Destructor
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called" << std::endl;
}
// Parameter constructor
ClapTrap::ClapTrap(const std::string &newName){
	std::cout << "ClapTrap Parameter constructor called" << std::endl;
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
		energyPoint--;
		// 0xFFFFFFFF == 11111111 11111111 11111111 11111111  MAX UINT32 value
		if (static_cast<unsigned long>(hitPoint) + amount <= 0xFFFFFFFF)
		{
			hitPoint += amount;
			std::cout << "ClapTrap " << name << " repairs itself by " << amount
			<< " hitpoints. (HP remaining: " << hitPoint << ")" << std::endl;
		}
		else
		{
			amount = 0xFFFFFFFF - hitPoint;
			hitPoint = 0xFFFFFFFF;
			if (amount == 0)
				std::cout << "ClapTrap " << name << " reach max HP and won't repair itself (HP remaining: "
				<< hitPoint << ")" << std::endl;
			else
				std::cout << "ClapTrap " << name << " repairs itself by " << amount
				<< " hitpoints. (HP remaining: " << hitPoint << ")" << std::endl;
		}
		
	}
	else {
		if (hitPoint > 0)
			std::cout << "ClapTrap " << name << " has no energy to repair itself." << std::endl;
		else
			std::cout << "ClapTrap " << name << " has no hitpoints and cannot repair itself." << std::endl;
	}
}

std::string	ClapTrap::getName(void) const {
	return (name);
}

unsigned int	ClapTrap::getHP(void) const {
	return (hitPoint);
}

unsigned int	ClapTrap::getEP(void) const {
	return (energyPoint);
}

unsigned int	ClapTrap::getATK(void) const {
	return (attackDmg);
}
