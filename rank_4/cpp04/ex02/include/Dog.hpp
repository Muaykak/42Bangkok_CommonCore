/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:50:56 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:27:51 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog( const Dog &other );
		Dog &operator=( const Dog &other );
		~Dog();

		void	makeSound() const;
		void	setIdea( unsigned int index, const std::string &new_idea );
		std::string	getIdea( unsigned int index ) const;
};

#endif