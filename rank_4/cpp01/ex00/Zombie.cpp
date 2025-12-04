/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 22:26:08 by srussame          #+#    #+#             */
/*   Updated: 2025/11/28 22:26:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	name = "defaultName";
	std::cout << name << ": Default Constructor Called." << std::endl;
}

Zombie::~Zombie(){
	std::cout << name << ": Destructor Called." << std::endl;
}

Zombie::Zombie(std::string newName){
	name = newName;
	std::cout << name << ": Parameter Constructor Called." << std::endl;
}

void	Zombie::announce( void ){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
