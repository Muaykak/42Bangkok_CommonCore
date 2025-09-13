/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:43:46 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 13:51:21 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap Dafault Constructor Called" << std::endl;
	this->setHP(100);
	this->setEnergy(100);
	this->setAtkDmg(30);
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name){
	std::cout << "FragTrap Parameterized Constructor Called by " << name << std::endl;
	this->setHP(100);
	this->setEnergy(100);
	this->setAtkDmg(30);
}

FragTrap::FragTrap( const FragTrap &other ){
	std::cout << "FragTrap Copy Constructor Called by " << other.getName() << std::endl;
	this->operator=(other);
}

FragTrap &FragTrap::operator=( const FragTrap &other ) {
	std::cout << "FragTrap Copy Assignment Operator Called by" << other.getName() << std::endl;
	this->setHP(other.getHP());
	this->setEnergy(other.getEnergy());
	this->setAtkDmg(other.getAtkDmg());
	this->setName(other.getName());
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor Called by " << this->getName() << std::endl;
}

void	FragTrap::highFivesGuys( void ){
	std::cout << "FragTrap " << this->getName() << " : Good, High Five!" << std::endl;
}