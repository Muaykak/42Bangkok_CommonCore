/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numset_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:55:56 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 20:56:02 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_numset(char *str);

/*		use ft_split() to split the given argument into char** 
		return NULL if wrong format, out of range integer, or something error
*/
char	***get_numsets(int argc, char **argv)
{
	char	***num_sets;
	int		i;

	if (check_format(argc, argv) == 0)
		return (NULL);
	num_sets = (char ***)ft_calloc(argc, sizeof(char **));
	if (num_sets == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		num_sets[i - 1] = get_numset(argv[i]);
		if (num_sets[i - 1] == NULL)
		{
			free_numsets(num_sets);
			return (NULL);
		}
		i++;
	}
	return (num_sets);
}

/* sub-fuction of get_numset()
		This function split the string into an array of strings
			using ft_split()  also check if that number in string 
			format is in the integer range or not 
		if False return NULL */
static char	**get_numset(char *str)
{
	char	**numset;
	int		i;

	if (str == NULL)
		return (NULL);
	numset = ft_split(str, ' ');
	if (numset == NULL)
		return (NULL);
	i = 0;
	while (numset[i] != NULL)
	{
		if (check_int_limit(numset[i]) == 0)
		{
			ft_free_split(numset);
			return (NULL);
		}
		i++;
	}
	return (numset);
}
