/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:17 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 16:28:28 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iomanip>

void	printStatus(ClapTrap &obj){
	std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
	std::cout << "Name: " << obj.getName() << std::endl;
	std::cout << "HP: " << obj.getHP() << std::endl;
	std::cout << "EP: " << obj.getEP() << std::endl;
	std::cout << "ATK: " << obj.getATK() << std::endl;
	std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
}

void printSection(const std::string &toPrint){
	std::cout << std::endl << std::left << std::setw(50) << std::setfill('-')
	<< "---- " + toPrint << std::endl;
	return ;
}

void claptrapTest(void){

	printSection("ClapTrap john(\"John\"); instantiate");
	ClapTrap	john("John");
	printSection("ClapTrap d; instantiate");
	ClapTrap	d;
	printSection("ClapTrap copy(john); instantiate");
	ClapTrap	copy(john);
	printSection("Check Copy Constructor");
	printStatus(copy);
	printStatus(john);

	printSection("john.attack() until no energy");
	for (int i = 0; i < 11; i++)
		john.attack("Kid");
	for (int i = 0; i < 3; i++)
		john.takeDamage(8);
	d = john;
	printSection("Check Copy Assignment Operator");
	printStatus(john);
	printStatus(d);
	printSection("d = john; then check b.beRepaired");
	d.beRepaired(1); // Should not repair because no hp

	printSection("ClapTrap roboid(\"Juliet\"); instantiate");
	ClapTrap	roboid("Juliet");

	printSection("roboid.beRepaired until no energy");
	for (int i = 0; i < 11; i++)
		roboid.beRepaired(0xFFFFFFFF / 2);

	printSection("4 Destructor should called for 4 objects");

}

int	main(void)
{
	claptrapTest();
	return (0);
}