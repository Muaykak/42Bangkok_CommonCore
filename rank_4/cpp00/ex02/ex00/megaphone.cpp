/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:19:06 by srussame          #+#    #+#             */
/*   Updated: 2025/09/04 12:19:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	str_to_upper(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
		std::cout << static_cast<char>(std::toupper(*(str++)));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
		str_to_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}

/*
	Need to Explain about What and why #include <iostream> is different from C

	also, what is std::  '<<' and '>>' what is it used for 

		what does std::endl do and how is it different from just put '\n' at
			the end of the string ?
	
	what is <cctype>  ? (i only know that i come from c <ctype.h> also part 
	of standard library )
*/
