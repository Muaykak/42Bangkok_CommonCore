/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:50:49 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 13:11:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*array;

	if (N < 1)
	{
		std::cerr << "N=" << N << ". Cannot be negative or Zero" << std::endl;
		return (NULL);
	}
	array = new Zombie[N];
	if (array == NULL)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		array[i].setName(name);
	}
	return (array);
}
