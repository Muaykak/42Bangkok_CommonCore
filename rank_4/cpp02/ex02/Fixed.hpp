/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:43 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 17:17:50 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> //for roundf()

class	Fixed
{
	private:
		int	num;
		static const int fractionalBits = 8;
	public:
		Fixed(); // default constructor 
		Fixed(const Fixed &obj); // copy constructor 
		Fixed	&operator=(const Fixed &obj); // copy assignment operator
		~Fixed(); // destructor 

		Fixed(const int int_num);
		Fixed(const float float_num);

		//Comparison operator
		bool	operator>(const Fixed& obj) const ;
		bool	operator<(const Fixed& obj) const ;
		bool	operator>=(const Fixed& obj) const ;
		bool	operator<=(const Fixed& obj) const ;
		bool	operator==(const Fixed& obj) const ;
		bool	operator!=(const Fixed& obj) const ;

		//Arithmetic operator
		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;

		// Increment / decrement operator
		// pre
		Fixed	&operator++();
		Fixed	&operator--();
		// post 
		Fixed	operator++(int incre);
		Fixed	operator--(int decre);


		/* const here is to promise that this member 
		function does not modify any member variables*/
		int	getRawBits( void ) const;
		void setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);

#endif

/*
Normal member function need to be call from an instance of a class
(through the declared pointer to that class,
or declaring an object of that class)(every normal member function
always implicitly have the pointer (this) to its function.
Allowing them to
access its current object)

static member function inside a class can be called with out an
instance of a class. Therefore it cannot access non-static members
of a class.
*/

// // print the binary of the obj

// template<typename T>
// std::string	stringBinary(const T &data){
// 	size_t	size = sizeof(data) - 1;
// 	const unsigned char *cur = reinterpret_cast<const unsigned char *>(&data);
// 	std::string	binstr;

// 	while (size >= 0){
// 		for (int j = 7; j >= 0; j--){
// 			binstr += static_cast<char>(((cur[size] & ((unsigned char)1 << j)) >> j) + 48);
// 		}
// 		binstr += ' ';
// 		if (size == 0)
// 			break ;
// 		size--;
// 	}
// 	return (binstr);
// }
