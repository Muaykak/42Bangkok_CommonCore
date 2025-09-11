/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:43 by srussame          #+#    #+#             */
/*   Updated: 2025/09/11 22:48:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int _fractional_bits = 8;
	public:
		//Orthodox Constructor
		Fixed();
		Fixed( const Fixed &copy );
		Fixed	&operator=(const Fixed &other);
		~Fixed();

		Fixed( const int num );
		Fixed( const float float_num );
		float	toFloat( void ) const;
		int	toInt( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed_num);

#endif