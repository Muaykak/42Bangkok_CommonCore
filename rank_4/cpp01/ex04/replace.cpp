/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:32:19 by srussame          #+#    #+#             */
/*   Updated: 2025/09/09 23:33:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static void	replaceLine( std::string &line, const std::string &s1, const std::string &s2 )
{
	if (s1.empty() || line.empty())
		return ;

	std::string temp;
	size_t		find_index;
	size_t		end_index = 0;
	std::string sub1;
	while (true)
	{
		find_index = line.find(s1, end_index);
		if (find_index == line.npos)
		{
			temp.append(line.substr(end_index, line.length()));
			break ;
		}
		sub1 = line.substr(end_index, find_index - end_index);
		temp.append(sub1);
		end_index = find_index + s1.length();
		temp.append(s2);
	}
	line = temp;
}

bool	replace( std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2)
{
	std::string read_string;

	while (!infile.eof())
	{
		if (infile.fail() || outfile.fail())
		{
			std::cerr << "Error: problem when read/write file" << std::endl;
			return (false);
		}
		std::getline(infile, read_string);
		replaceLine(read_string, s1, s2);
		outfile << read_string;
		std::cout << read_string;
		if (!infile.eof())
		{
			std::cout << std::endl;
			outfile << "\n";
		}
	}
	if (outfile.is_open())
		outfile.close();
	if (infile.is_open())
		infile.close();
	return (true);
}
