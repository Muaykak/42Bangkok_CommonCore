/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:46 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 00:58:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	num = 0;
}

// copy constructor
Fixed::Fixed(Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	operator=(copy);
}

// copy assignment operator
Fixed	&Fixed::operator=(const Fixed& copy){
	std::cout << "Copy assignment operator called" << std::endl;
	num = copy.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num;
};

void	Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
};