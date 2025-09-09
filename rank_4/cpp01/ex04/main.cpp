/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:11:54 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 18:19:00 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Need 3 arguments" << std::endl;
		return (1);
	}

	std::ifstream my_file(argv[1]);
	if (my_file.good() == false)
	{
		std::cerr << "The file cannot open" << std::endl;
		return (1);
	}
	my_file.close();
	(void)argv;
}