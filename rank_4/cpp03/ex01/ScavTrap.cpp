/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:13:27 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 16:21:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap Default constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDmg = 20;
	guardStatus = false;
}
ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj){
	std::cout << "ScavTrap  Copy constructor called" << std::endl;
	if (this != &obj)
		guardStatus = obj.guardStatus;
}
ScavTrap&	ScavTrap::operator=(const ScavTrap& obj) {
	std::cout << "ScavTrap Copy asignment operator called" << std::endl;
	if (this != &obj){
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDmg = obj.attackDmg;
		guardStatus = obj.guardStatus;
	}
	return (*this);
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName){
	std::cout << "ScavTrap Parameter constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDmg = 20;
	guardStatus = false;
}

void	ScavTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0){
		std::cout << "ScavTrap " << name << " attacks " << target << " causing "
		<< attackDmg << " points of damage!" << std::endl;
		energyPoint--;
	}
	else {
		if (hitPoint > 0)
			std::cout << "ScavTrap " << name << " has no energy to attack!" << std::endl;
		else
			std::cout << "ScavTrap " << name << " has no hitpoints and cannot attack!" << std::endl;
	}
}

void	ScavTrap::guardGate(){
	if (guardStatus)
		std::cout << "ScavTrap " << name << " is already set to Gate keeper mode." << std::endl;
	else {
		std::cout << "ScavTrap " << name << " turn on Gate keeper mode." << std::endl;
		guardStatus = true;
	}
}

bool	ScavTrap::getGuardStatus() const {
	return (guardStatus);
}
