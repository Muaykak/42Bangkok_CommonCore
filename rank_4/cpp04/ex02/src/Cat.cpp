/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:51:32 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:23:48 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat( const Cat &other ){
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->_brain = new Brain(*(other._brain));
	this->operator=(other);
}

Cat &Cat::operator=( const Cat &other ){
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	this->type = other.getType();
	*this->_brain = *other._brain;
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}

void	Cat::setIdea(unsigned int index, const std::string &new_idea ){
	if (index < 100)
		this->_brain->ideas[index] = new_idea;
	else
		std::cerr << "Error: Cat::setIdea() => index must less than 100" << std::endl;
}

std::string	Cat::getIdea( unsigned int index ) const {
	if (index < 100)
		return (this->_brain->ideas[index]);
	else
	{
		std::cerr << "Error: Cat::getIdea() => index must less than 100" << std::endl;
		return ("");
	}
}
