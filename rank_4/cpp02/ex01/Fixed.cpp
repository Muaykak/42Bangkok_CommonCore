/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:46 by srussame          #+#    #+#             */
/*   Updated: 2025/09/11 23:07:27 by srussame         ###   ########.fr       */
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

Fixed::Fixed( const int num ){
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits((num << this->_fractional_bits) | ((num >> 31) << 31));
}

Fixed::Fixed( const float float_num ){
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_num * (1 << this->_fractional_bits)));
}

float	Fixed::toFloat( void ) const {
	return ((float)(this->getRawBits()) / (1 << this->_fractional_bits));
}

int	Fixed::toInt( void ) const {
	int	num = this->getRawBits();
	return ((((num << 1) >> 1) >> this->_fractional_bits) | ((num >> 31) << 31));
}

int		Fixed::getRawBits( void ) const{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ){
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed_num)
{
	os << fixed_num.toFloat();
	return (os);
}
