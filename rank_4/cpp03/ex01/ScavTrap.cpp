/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:32:44 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 13:26:09 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap Dafault Constructor Called" << std::endl;
	this->setHP(100);
	this->setEnergy(50);
	this->setAtkDmg(20);
	this->_gate_keeper_mode = false;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name){
	std::cout << "ScavTrap Parameterized Constructor Called by " << name << std::endl;
	this->setHP(100);
	this->setEnergy(50);
	this->setAtkDmg(20);
	this->_gate_keeper_mode = false;
}

ScavTrap::ScavTrap( const ScavTrap &other ){
	std::cout << "ScavTrap Copy Constructor Called by " << other.getName() << std::endl;
	this->operator=(other);
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &other ){
	std::cout << "ScavTrap Copy Assignment Operator Called by" << other.getName() << std::endl;
	this->setHP(other.getHP());
	this->setEnergy(other.getEnergy());
	this->setAtkDmg(other.getAtkDmg());
	this->setName(other.getName());
	return (*this);
}

void	ScavTrap::attack( const std::string &target ){
	if (this->getEnergy() > 0 && this->getHP() > 0)
	{
		this->setEnergy(this->getEnergy() - 1);
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAtkDmg() << " points of damage!, energy remaining: " << this->getEnergy() << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->getName() << " Doesn't have energy to attack. / Doesn't have any HP left." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor Called by " << this->getName() << std::endl;
}

void	ScavTrap::guardGate(){
	if (this->_gate_keeper_mode == false)
	{
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
		this->_gate_keeper_mode = true;
	}
	else
		std::cout << "ScavTrap " << this->getName() << " is already in Gate keeper mode." << std::endl;
}
