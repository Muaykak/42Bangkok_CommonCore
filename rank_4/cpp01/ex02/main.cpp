/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:42 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 14:05:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void){
	// use parameterized constructor to initialize the string
	std::string brain("HI THIS IS BRAIN");

	// this is normal pointer we already know from C
	std::string* stringPTR = &brain;

	/*
	This is 'reference' variable: is an ALIAS to an
	already-existing object or function. (from cppreference.com)

	A reference is REQUIRED to be initialize to a valid object or function
	*/
	std::string& stringREF = brain;

	std::cout << "Memory Address of each variable" << std::endl;
	// now its usage is the same as 'brain' variable
	// changing stringREF value is the same as changing brain
	// so the address of variable is the same. Only name is the differene.
	std::cout << "brain: " << &brain << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "The value of each variable" << std::endl;
	std::cout << "brain: " << brain << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	// think of Reference as a Constant pointer that automatically dereference
}
