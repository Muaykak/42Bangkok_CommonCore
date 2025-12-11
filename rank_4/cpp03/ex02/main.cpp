/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:17 by srussame          #+#    #+#             */
/*   Updated: 2025/12/11 16:28:37 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iomanip>

void	printStatus(ClapTrap &obj){
	std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
	std::cout << "Name: " << obj.getName() << std::endl;
	std::cout << "HP: " << obj.getHP() << std::endl;
	std::cout << "EP: " << obj.getEP() << std::endl;
	std::cout << "ATK: " << obj.getATK() << std::endl;
	std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
}

void	printStatus(ScavTrap &obj){
	std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
	std::cout << "Name: " << obj.getName() << std::endl;
	std::cout << "HP: " << obj.getHP() << std::endl;
	std::cout << "EP: " << obj.getEP() << std::endl;
	std::cout << "ATK: " << obj.getATK() << std::endl;
	std::cout << "Guardgate: " << (obj.getGuardStatus()  == true ? "ON" : "OFF") << std::endl;
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

void scavtrapTest(){
	{
		printSection("ScavTrap a; Default Constructor");
		ScavTrap a;

		printSection("Check ScavTrap a status");
		printStatus(a);
		printSection("ScavTrap a Destructor");
	}
	{
		// parameter constructor
		printSection("ScavTrap b(\"John\"); Parameter Constructor");
		ScavTrap b("John");

		printSection("Check ScavTrap b status");
		printStatus(b);
		printSection("ScavTrap b Destructor");
	}
	{
		printSection("Copy constructor test");
		//copy constructor
		ScavTrap a;

		a.takeDamage(20);
		a.guardGate();
		printSection("ScavTrap b copy constructor");
		ScavTrap b(a);
		printStatus(a);
		printStatus(b);
		printSection("Destructor a b");
	}
	{
		//Allocation test
		printSection("allocation test #1");
		printSection("ScavTrap *ptr = new ScavTrap(\"Tom\");");
		ScavTrap *ptr = new ScavTrap("Tom");
		ptr->attack("Thailand");
		printSection("delete ptr");
		delete ptr;
	}
	{
		// Allocation test # 2
		printSection("allocation test #2");
		printSection("ClapTrap *ptr = new ScavTrap(\"Tom\");");
		ClapTrap *ptr = new ScavTrap("Tom");
		ptr->attack("Thailand");
		printSection("delete ptr");
		delete ptr;
	}
	{
		// test all functionality
		printSection("test more functions");
		
		ScavTrap	a("Smith");
		ScavTrap	b("Pad");

		a.getGuardStatus();
		a.getGuardStatus();
		b = a;
		while (b.getHP() > 0){
			b.takeDamage(50);
		}
		a.attack("Jelly");
		b.beRepaired(100);
		printSection("a and b Destructor");
	}
}

void fragtrapTest(){
	{
		printSection("FragTrap a; Default Constructor");
		FragTrap a;

		printSection("Check FragTrap a status");
		printStatus(a);
		printSection("FragTrap a Destructor");
	}
	{
		// parameter constructor
		printSection("FragTrap b(\"John\"); Parameter Constructor");
		FragTrap b("John");

		printSection("Check FragTrap b status");
		printStatus(b);
		printSection("FragTrap b Destructor");
	}
	{
		printSection("Copy constructor test");
		//copy constructor
		FragTrap a;

		a.takeDamage(20);
		a.highFivesGuys();
		printSection("FragTrap b copy constructor");
		FragTrap b(a);
		printStatus(a);
		printStatus(b);
		printSection("Destructor a b");
	}
	{
		//Allocation test
		printSection("allocation test #1");
		printSection("FragTrap *ptr = new FragTrap(\"Tom\");");
		FragTrap *ptr = new FragTrap("Tom");
		ptr->attack("Thailand");
		printSection("delete ptr");
		delete ptr;
	}
	{
		// Allocation test # 2
		printSection("allocation test #2");
		printSection("ClapTrap *ptr = new FragTrap(\"Tom\");");
		ClapTrap *ptr = new FragTrap("Tom");
		ptr->attack("Thailand");
		printSection("delete ptr");
		delete ptr;
	}
	{
		// test all functionality
		printSection("test more functions");
		
		FragTrap	a("Smith");
		FragTrap	b("Pad");

		a.highFivesGuys();
		a.highFivesGuys();
		b = a;
		while (b.getHP() > 0){
			b.takeDamage(50);
		}
		a.attack("Jelly");
		b.beRepaired(100);
		printSection("a and b Destructor");
	}
}

int	main(void)
{
	fragtrapTest();
	return (0);
}