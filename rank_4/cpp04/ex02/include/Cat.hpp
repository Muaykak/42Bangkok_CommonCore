/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:50:34 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 20:18:04 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat( const Cat &other );
		Cat &operator=( const Cat &other );
		~Cat();

		void	makeSound() const;
		void	setIdea( unsigned int index, const std::string &new_idea );
		std::string	getIdea( unsigned int index ) const;
};

#endif