/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:17 by srussame          #+#    #+#             */
/*   Updated: 2025/11/28 22:26:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <cstdlib>

// Zombie class
int main(){

	Zombie	normal("Imposter");
	
	int	hordeCount = 5;
	// if (argc == 2)
	// 	hordeCount = std::atoi(argv[1]);

	// Use Color to easily tell which constructor or destructor were 
	// called inside the function or outside
	std::cout << YEL << std::flush;
	Zombie *zomhorde = zombieHorde(hordeCount, "John");
	std::cout << COLOR_RESET << std::flush;

	for (int i = 0; i < hordeCount; i++){
		zomhorde[i].announce();
	}


	std::cout << GRN << std::flush;
	// delete must uses with new -> allocate and deallocate one object
	// delete[] must uses with new[] -> allocate and deallocate an array of object
	delete[] zomhorde;
	std::cout << COLOR_RESET << std::flush;

	// new and delete must use together
	// new will calls the object's constructor while malloc does not
	// delete will called destructor of the object but free does not
	// cannot cross with malloc or free
}

/*
std::flush used to flush the output 
	to show immediately to the screen

Normally std::cout waits for std::endl before flushing the output
*/