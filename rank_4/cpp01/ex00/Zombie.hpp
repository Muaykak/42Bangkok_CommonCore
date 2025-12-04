/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:13 by srussame          #+#    #+#             */
/*   Updated: 2025/11/28 22:26:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie {
	public:
		Zombie(); // defalt initialization zombie will be named "defaultName"
		Zombie(std::string newName);
		~Zombie();
		void	announce( void ); // announe its name and its sound
	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif
