/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:24 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 13:27:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->setHP(10);
	this->setEnergy(10);
	this->setAtkDmg(0);
	this->setName("Default_name");
}

ClapTrap::ClapTrap( const std::string &new_name){
	std::cout << "ClapTrap Parameterized Constructor called by " << new_name << std::endl;
	this->setHP(10);
	this->setEnergy(10);
	this->setAtkDmg(0);
	this->setName(new_name);
}

ClapTrap::ClapTrap( const ClapTrap &other ){
	std::cout << "ClapTrap Copy Constructor called by " << other.getName() << std::endl;
	this->operator=(other);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap Copy assignment operator called by " << other.getName() << std::endl;
	this->setHP(other.getHP());
	this->setEnergy(other.getEnergy());
	this->setAtkDmg(other.getAtkDmg());
	this->setName(other.getName());
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called by " << this->getName() << std::endl;
}

std::string	ClapTrap::getName( void ) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHP( void ) const {
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergy( void ) const {
	return (this->_energy_points);
}
unsigned int	ClapTrap::getAtkDmg( void ) const {
	return (this->_attack_damage);
}

void	ClapTrap::setName( const std::string &name ){
	this->_name = name;
}

void	ClapTrap::setHP( unsigned int hp ){
	this->_hit_points = hp;
}

void	ClapTrap::setAtkDmg( unsigned int atk ){
	this->_attack_damage = atk;
}

void	ClapTrap::setEnergy( unsigned int energy ){
	this->_energy_points = energy;
}

void	ClapTrap::attack(const std::string& target){
	if (this->getEnergy() > 0 && this->getHP() > 0)
	{
		this->setEnergy(this->getEnergy() - 1);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAtkDmg() << " points of damage!, energy remaining: " << this->getEnergy() << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " Doesn't have energy to attack. / Doesn't have any HP left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->setHP(amount >= this->getHP() ? 0 : this->getHP() - amount);
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage";
	if (this->_hit_points > 0)
		std::cout << ", HP remaining: " << this->getHP() << std::endl;
	else
		std::cout << ", No HP remaining." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->getEnergy() > 0 && this->getHP() > 0)
	{
		this->setHP(this->getHP() + amount);
		this->setEnergy(this->getEnergy() - 1);
		std::cout << "ClapTrap " << this->getName() << " repaired itself by " << amount << ", Now its Hit points increased to " << this->getHP() << ", energy remaining: " << this->getEnergy() << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " Doesn't have energy to Repair itself. / Doesn't have any HP left." << std::endl;
}
