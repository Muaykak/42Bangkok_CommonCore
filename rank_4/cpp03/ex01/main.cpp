/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:17 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 23:28:24 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// // no virtual on Parent destructor test
// int	main(void)
// {
// 	ClapTrap *ptr = new ScavTrap("John");
// 	delete ptr;
// 	return (0);
// }

// // check constructor
// int main(void){
// 	ScavTrap	a("Zim");
// 	ScavTrap	b;
// 	ScavTrap	c(b);
// 	ScavTrap	e;

// 	e = a;
// }

// test each override function
int main(void){
	ScavTrap t("Jiggy");
	ScavTrap j("Ling");

	for (int i = 0; i < 10; i ++){
		j.attack("Jiggy");
		t.takeDamage(20);
		t.beRepaired(5);
	}
}

// // test guardGate()
// int main(void){
// 	ScavTrap	a("Steve");
// 	ScavTrap	b("Heok");
// 	a.guardGate();
// 	b = a;
// 	b.guardGate();
// }