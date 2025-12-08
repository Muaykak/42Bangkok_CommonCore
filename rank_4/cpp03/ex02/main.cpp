/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:17 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 23:26:26 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// // no virtual on Parent destructor test
// int	main(void)
// {
// 	ClapTrap *ptr = new FragTrap("John");
// 	delete ptr;
// 	return (0);
// }

// // check constructor
// int main(void){
// 	FragTrap	a("Zim");
// 	FragTrap	b;
// 	FragTrap	c(b);
// 	FragTrap	e;

// 	e = a;
// }

// // test each override function
// int main(void){
// 	FragTrap t("Jiggy");
// 	FragTrap j("Ling");

// 	for (int i = 0; i < 10; i ++){
// 		j.attack("Jiggy");
// 		t.takeDamage(20);
// 		t.beRepaired(5);
// 	}
// }

// test guardGate()
int main(void){
	FragTrap	a("Steve");
	FragTrap	b("Heok");
	a.highFivesGuys();
}