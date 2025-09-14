/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:50:02 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:49:05 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal( const Animal &other );
		Animal( const std::string &type );
		Animal &operator=( const Animal &other );
		virtual ~Animal();

		std::string	getType() const;
		virtual void	makeSound() const = 0;
};
#endif