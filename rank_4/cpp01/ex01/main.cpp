/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:10:26 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 13:08:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 2147483647;
	std::string	name = "Johnny";
	Zombie	*horde = zombieHorde(N, name);

	for (int i = 0;i < N; i++)
	{
		std::cout << "[" << i + 1 << "]: ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}