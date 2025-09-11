/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:46 by srussame          #+#    #+#             */
/*   Updated: 2025/09/12 02:00:51 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	this->_value = 0;
}

Fixed::Fixed( const Fixed &other ){
	this->operator=(other);
}

Fixed	&Fixed::operator=(const Fixed &other){
	this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
}

Fixed::Fixed( const int num ){
	this->setRawBits((num << this->_fractional_bits) | ((num >> 31) << 31));
}

Fixed::Fixed( const float float_num ){
	this->setRawBits((int)roundf(float_num * (1 << this->_fractional_bits)));
}

bool	Fixed::operator<(const Fixed &other){
	return (this->_value < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other){
	return (this->_value <= other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other){
	return (this->_value > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other){
	return (this->_value > other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other){
	return (this->_value == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other){
	return (this->_value != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other){
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other){
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other){
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other){
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::min( Fixed &a, Fixed &b ){
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b ){
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b ){
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b ){
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed	&Fixed::operator++(){
	this->setRawBits(this->_value + 1);
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed	temp(*this);
	this->setRawBits(this->_value + 1);
	return (temp);
}

Fixed	&Fixed::operator--(){
	this->setRawBits(this->_value - 1);
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	temp = this->getRawBits();
	--*this;
	return (temp);
}

/*
		//Arithmetic operators
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);

		// ++, -- operators
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		// overloaded member function
		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	&min( const Fixed &a, const Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );
		static Fixed	&max( const Fixed &a, const Fixed &b );
*/

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
