/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:02:31 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:42:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string &type ){
	std::cout << "WrongAnimal Parameterized Constructor Called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ){
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	this->operator=(other);
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ){
	std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
	this->type = other.getType();
	return (*this);
}
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}
