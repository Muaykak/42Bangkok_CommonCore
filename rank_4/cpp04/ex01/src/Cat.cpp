/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:51:32 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 15:55:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat( const Cat &other ){
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->operator=(other);
}

Cat &Cat::operator=( const Cat &other ){
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	this->type = other.getType();
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}

