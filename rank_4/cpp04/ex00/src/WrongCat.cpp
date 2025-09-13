/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:12:53 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 16:16:36 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ){
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	this->operator=(other);
}

WrongCat &WrongCat::operator=( const WrongCat &other ){
	std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
	this->type = other.getType();
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << ">> asfda(*&(*sdfasf23ad 2klj1h2nadkjas8d3&@!@^#$%&!" << std::endl;
}