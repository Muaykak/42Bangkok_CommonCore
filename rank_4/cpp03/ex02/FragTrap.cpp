/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 23:22:30 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 23:25:32 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap " << name << ": Default constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDmg = 30;
}
FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj){
	std::cout << "FragTrap " << name << ": Copy constructor called" << std::endl;
	operator=(obj);
}
FragTrap&	FragTrap::operator=(const FragTrap& obj) {
	std::cout << "FragTrap " << obj.name << ": Copy asignment operator called" << std::endl;
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDmg = obj.attackDmg;
	return (*this);
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << ": Destructor called" << std::endl;
}
FragTrap::FragTrap(const std::string& newName) : ClapTrap(newName){
	std::cout << "FragTrap " << name << ": Parameter constructor called" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDmg = 30;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << name << ": \"Let's High Fives guys!\"" << std::endl;
}
