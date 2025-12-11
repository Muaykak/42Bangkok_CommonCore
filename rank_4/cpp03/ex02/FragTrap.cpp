/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:22:30 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 16:27:05 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap Default constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDmg = 30;
}
FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj){
	std::cout << "FragTrap Copy constructor called" << std::endl;
}
FragTrap&	FragTrap::operator=(const FragTrap& obj) {
	std::cout << "FragTrap Copy asignment operator called" << std::endl;
	if (this != &obj){
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDmg = obj.attackDmg;
	}
	return (*this);
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}
FragTrap::FragTrap(const std::string& newName) : ClapTrap(newName){
	std::cout << "FragTrap Parameter constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDmg = 30;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << name << ": \"Let's High Fives guys!\"" << std::endl;
}
