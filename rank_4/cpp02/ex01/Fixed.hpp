/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:43 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 12:26:28 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
		float	toFloat( void ) const;
		int		toInt( void ) const;


		/* const here is to promise that this member 
		function does not modify any member variables*/
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);

#endif

// // print the binary of the obj

// template<typename T>
// void	printBinary(const T &data){
// 	size_t	size = sizeof(data) - 1;
// 	const unsigned char *cur = reinterpret_cast<const unsigned char *>(&data);
// 	while (size >= 0){
// 		for (int j = 7; j >= 0; j--){
// 			std::cout << ((cur[size] & ((unsigned char)1 << j)) >> j);
// 		}
// 		std::cout << " ";
// 		if (size == 0)
// 			break ;
// 		size--;
// 	}
// 	std::cout << std::endl;
// }
