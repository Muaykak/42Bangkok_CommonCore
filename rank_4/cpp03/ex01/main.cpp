/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 02:10:17 by srussame          #+#    #+#             */
/*   Updated: 2025/09/13 13:33:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Test("Johnny");
	ClapTrap	*ptr;

	Test.guardGate();
	Test.beRepaired(200);
	Test.attack("Prayut");
	Test.guardGate();
	ptr = &Test;
	ptr->attack("Me");
	return (0);
}