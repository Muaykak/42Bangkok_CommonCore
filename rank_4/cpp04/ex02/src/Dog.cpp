/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:41:12 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:27:41 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog &other ){
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->_brain = new Brain(*(other._brain));
	this->operator=(other);
}

Dog &Dog::operator=( const Dog &other ){
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	this->type = other.getType();
	*this->_brain = *other._brain;
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog Destructor Called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}

void	Dog::setIdea(unsigned int index, const std::string &new_idea ){
	if (index < 100)
		this->_brain->ideas[index] = new_idea;
	else
		std::cerr << "Error: Dog::setIdea() => index must less than 100" << std::endl;
}

std::string	Dog::getIdea( unsigned int index ) const {
	if (index < 100)
		return (this->_brain->ideas[index]);
	else
	{
		std::cerr << "Error: Dog::getIdea() => index must less than 100" << std::endl;
		return ("");
	}
}
