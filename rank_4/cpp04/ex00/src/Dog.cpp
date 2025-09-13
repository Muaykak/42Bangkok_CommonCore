/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:41:12 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 15:56:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog( const Dog &other ){
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->operator=(other);
}

Dog &Dog::operator=( const Dog &other ){
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	this->type = other.getType();
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog Destructor Called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
