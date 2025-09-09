/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:11:54 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 23:33:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Need 3 arguments" << std::endl;
		return (1);
	}

	std::ifstream my_file(argv[1]);

	if (my_file.is_open() == false)
	{
		std::cerr << "The file cannot open" << std::endl;
		return (1);
	}

	std::ofstream outfile;

	outfile.open(OUTFILE_NAME);
	if (outfile.is_open() == false)
	{
		std::cerr << "The outfile cannot open" << std::endl;
		return (1);
	}
	if (replace(my_file, outfile, argv[2], argv[3]) == false)
		return (1);
	return (0);
}
