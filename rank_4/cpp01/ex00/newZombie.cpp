/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:25:56 by srussame          #+#    #+#             */
/*   Updated: 2025/11/28 22:26:02 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
	// 'new' is a operator in c++ used to
	// allocate memory to heap (i think)
	// new data_type[array_size]
	// in this function,
	// passed 'Zombie' datatype (which a class)
	// we can use parameterized constructor here
	// if 'new Zombie' it will use default constructor
	return (new Zombie(name));
}