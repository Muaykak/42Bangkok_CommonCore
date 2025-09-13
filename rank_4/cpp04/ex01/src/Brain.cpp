/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:24:16 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 16:33:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain( const Brain &other );
		Brain &operator=( const Brain &other );
		~Brain();

		void	setIdea(unsigned int index, const std::string &new_idea );
		std::string	getIdea(unsigned int index) const;
};

#endif