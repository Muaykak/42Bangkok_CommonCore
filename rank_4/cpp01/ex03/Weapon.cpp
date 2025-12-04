/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:02:04 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 21:02:08 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
	type = "defaultWeapon";
	std::cout << type << ": default constructor called" << std::endl;
}

Weapon::~Weapon(){
	std::cout << type << ": destructor called" << std::endl;
}

Weapon::Weapon(std::string newType){
	setType(newType);
	std::cout << type << ": parameterized constructor called" << std::endl;
}


const std::string &Weapon::getType(){
	return (type);
}

void Weapon::setType(std::string newType){
	type = newType;
}
