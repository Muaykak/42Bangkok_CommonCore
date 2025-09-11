/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:46 by srussame          #+#    #+#             */
/*   Updated: 2025/09/11 18:54:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( const Fixed &other ){
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed	&Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
