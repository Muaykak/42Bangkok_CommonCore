/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:17 by srussame          #+#    #+#             */
/*   Updated: 2025/12/04 21:47:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	John("John");
	ClapTrap	Default;
	ClapTrap	Copy(John);

	for (int i = 0; i < 11; i++)
		John.attack("Kid");
	for (int i = 0; i < 3; i++)
		John.takeDamage(7);
	Default = John;
	Default.beRepaired(1);

	ClapTrap	Roboid("Juliet");

	for (int i = 0; i < 11; i++)
		Roboid.beRepaired(10);
	return (0);
}