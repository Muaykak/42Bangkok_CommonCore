/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:57:00 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 12:48:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie( const std::string &new_name );
		~Zombie();
		void		announce( void );
		void		setName( const std::string &new_name );
		std::string	getName( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

# endif