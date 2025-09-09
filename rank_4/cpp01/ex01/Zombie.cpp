/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:12:01 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 13:11:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	this->_name = "default_name";
}

Zombie::~Zombie(){
}

Zombie::Zombie(const std::string &new_name){
	this->_name = new_name;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void){
	return (this->_name);
}

void	Zombie::setName(const std::string &new_name)
{
	this->_name = new_name;
}