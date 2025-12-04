/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:43:01 by srussame          #+#    #+#             */
/*   Updated: 2025/11/29 21:00:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ){
	std::cout << "[DEBUG]: ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "[INFO]: ";
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking\
 for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[WARNING]: ";
	std::cout << "I think I deserve to have some extra bacon for free.\
 I\'ve been coming for years, whereas you started working here just \
last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "[ERROR]: ";
	std::cout << "This is unacceptable! I want to speak to the manager \
now." << std::endl;
}

void Harl::complain( std::string level ){
	// must have '&' to initialize these member functions to array of pointers
	void	(Harl::*pointer_to_member[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	harl_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (harl_level[i] == level)
		{
			// 'This' is a pointer to the current instance of the class
			// '->*' is called "Pointer to Member Operator". It is not the same as C.
			// '.*' = pointer to member of object operator
			// '->*' = pointer to member of pointer operator
			// '.' = member of object
			// '->' = member of pointer
			(this->*pointer_to_member[i])();
			return ;
		}
	}
	std::cout << "The level don't match with Harl's level!" << std::endl;
}

/*
the pointer to member only holds the address of the function.
but member function require an object to run
we need 'this' which is a pointer to the current object
and '->*' to execute the function of 'this'(the current object)

*** member function needs an object to work.
*/