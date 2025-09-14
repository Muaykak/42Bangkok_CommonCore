/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:52:15 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:46:21 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal( const std::string &type );
		WrongAnimal( const WrongAnimal &other );
		WrongAnimal &operator=( const WrongAnimal &other );
		virtual ~WrongAnimal();

		std::string getType() const ;
		virtual void	makeSound() const = 0;
};

#endif