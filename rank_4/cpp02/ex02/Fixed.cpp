/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:46 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 17:18:55 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	num = 0;
}

// copy constructor
Fixed::Fixed(const Fixed &copy){
	operator=(copy);
}

// copy assignment operator
Fixed	&Fixed::operator=(const Fixed& copy){
	num = copy.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(){
}


Fixed::Fixed(const int int_num){
	num = int_num << fractionalBits;
}

Fixed::Fixed(const float float_num){
	num = roundf(float_num * (1 << fractionalBits));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj){
	os << obj.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& obj) const {
	return (num > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const {
	return (num < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed& obj) const {
	return (num >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed& obj) const {
	return (num <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed& obj) const {
	return (num == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return (num != obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(num + obj.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(num - obj.getRawBits());
	return (result);
}

/*
	Explanation
	 (a * 2^fractionalBits) * (b * 2^fractionalBits) = result * 2^(fragtionalBits + fragtionalBits)

	 but we because our fixed point is int << fragtionalBits (* 2^fragtionalBits)
	then we need to
	(result * 2^(fractionalBits + fractionalBits)) / 2^fragtionalBits

	or simply    << fragtionalBits 

	cast to long long first to to handle overflow in calculation

*/
Fixed	Fixed::operator*(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(((long long)num * obj.getRawBits()) >> fractionalBits);
	return (result);
}

/*
same as multiplication but need to left shift before doing the division
*/
Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed result;
	result.setRawBits(((long long)num << fractionalBits) / obj.getRawBits());
	return (result);
}

Fixed	&Fixed::operator++(){
	num += 1;
	return (*this);
}

Fixed	&Fixed::operator--(){
	num -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int decre){
	Fixed temp(*this);
	num -= decre == 0 ? 1 : decre;
	return (temp);
}

Fixed	Fixed::operator++(int incre){
	Fixed temp(*this);

	num += incre == 0 ? 1 : incre;
	return (temp);
}

int	Fixed::getRawBits( void ) const {
	return num;
};

void	Fixed::setRawBits( int const raw ){
	num = raw;
};

float	Fixed::toFloat( void ) const {
	return (((float)num / (1 << fractionalBits)));
}

int		Fixed::toInt( void ) const {
	return (num >> fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed&b){
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed&b){
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed&b){
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed&b){
	return (a > b ? a : b);
}
