/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:03:43 by srussame          #+#    #+#             */
/*   Updated: 2025/09/11 01:20:50 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	_value;
		static const int _fractional_bits = 8;
	public:
		Fixed();
		Fixed( const Fixed &copy );
		Fixed	&operator=(const Fixed &other);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif