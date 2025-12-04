/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:25:50 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 15:50:55 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie class
int main(void){
	Zombie	z; // Create an object named "z" with the type of zombie class

	z.announce(); // Zombie with no name specified when initialize

	// Take std::string to construct an Zombie object then use its member
	// 'announce' to print that zombie to the screen
	randomChump("Steve");
	// See that Destructor called when we finished the randomChump
	// this variable created in the function will called Destructor when
	// It finished that Block scope

	// This Zombie object created on the heap
	// the function return the pointer that points to that Zombie
	// object that exists in heap memory.
	// that means we can use this object outside of its function scope
	Zombie	*ptr = newZombie("Timmy");

	ptr->announce();


	// The object that got created on the heap stack, In c++,
	// 'delete' is the operator that will free that memory of that
	// object in the heap
	// See that the Destructor of the that ptr object get called
	// when we use delete
	// delete ptr; 
	std::cout << "Program end" << std::endl; // Destructor will call after this
	delete ptr; //will delete after "Program end" if we put delete here

	// ** same as C. If we don't delete that pointer that hold allocated memory
	// memory leaks will occur.

}

// For me i think to allocate Zombie on stack is better because
// We don't have to pay attention whether that object got freed or not.

// but if we want to pass that object arounds between functions
// we need an object that exist on the heap