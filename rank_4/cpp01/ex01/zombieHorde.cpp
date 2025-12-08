/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:37 by srussame          #+#    #+#             */
/*   Updated: 2025/11/28 22:26:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Implement a function
// allocate N amount of Zombies in a SINGLE allocation
Zombie*	zombieHorde( int N, std::string name ){
	// new operator
	// new data_type[array_size]
	Zombie *ptr = new Zombie[N];

	for (int i = 0; i < N; i++){
		// use parameterized constructor Zombie(std::string)
		// can copy content to the object using
		// copy assignemt operator ('=')
		// which its default will just simply replace all of the
		// object's variable to the new one
		ptr[i] = Zombie(name);
	}
	return (ptr);
}