/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:57:31 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:42:54 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal( const Animal &other ){
	std::cout << "Animal Copy Constructor Called by " << other.getType() << std::endl;
	this->operator=(other);
}

Animal::Animal( const std::string &type ){
	std::cout << "Animal Parameterized Constructor Called by " << type << std::endl;
	this->type = type;
}


Animal &Animal::operator=( const Animal &other ){
	std::cout << "Animal Copy Assignment Operator Called by " << other.getType() << std::endl;
	this->type = other.getType();
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal Destructor Called by " << this->getType() << std::endl;
}

std::string	Animal::getType() const{
	return (this->type);
}
