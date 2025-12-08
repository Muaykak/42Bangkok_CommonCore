/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:43 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 00:47:41 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	num;
		static const int fractionalBits = 8;
	public:
		Fixed(); // default constructor 
		Fixed(Fixed &copy); // copy constructor 
		Fixed	&operator=(const Fixed &copy); // copy assignment operator
		~Fixed(); // destructor 

		/* const here is to promise that this member 
		function does not modify any member variables*/
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif