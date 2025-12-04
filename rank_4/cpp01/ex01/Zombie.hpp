/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:31 by srussame          #+#    #+#             */
/*   Updated: 2025/11/28 22:36:05 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

#define YEL "\e[0;33m"
#define GRN "\e[0;32m"
#define COLOR_RESET "\e[0m"

class	Zombie {
	public:
		Zombie(); // defalt initialization zombie will be named "defaultName"
		Zombie(std::string newName);
		~Zombie();
		void	announce( void ); // announe its name and its sound
	private:
		std::string name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif
