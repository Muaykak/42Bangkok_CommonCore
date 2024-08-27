/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:05:33 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 12:05:34 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_split_count(char const *s, char c);
size_t			ft_strcount_nochr(char const *s, char c);
int				ft_malloc_split(char **save, char const *s, char c);
void			ft_assign_split(char **save, char *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**save;

	save = (char **)malloc((ft_split_count(s, c) + 1) * sizeof(char *));
	if (save == 0 || s == 0)
		return (0);
	*(save + ft_split_count(s, c)) = 0;
	if (ft_malloc_split(save, s, c) < 1)
	{
		n = (-1 * ft_split_count(s, c));
		while (n > 0)
		{
			if (save[n] != 0)
				free(save[n]);
			n--;
		}
		if (save[n] != 0)
			free(save[n]);
		free(save);
		return (0);
	}
	ft_assign_split(save, (char *)s, c);
	return (save);
}

void	ft_assign_split(char **save, char *s, char c)
{
	size_t	i[4];

	i[0] = 0;
	i[1] = 0;
	while (*(s + i[0]) != '\0')
	{
		i[2] = ft_strcount_nochr((s + i[0]), c);
		if (i[2] != 0)
		{
			i[3] = 0;
			while (i[3] < i[2])
			{
				save[i[1]][i[3]] = s[i[0] + i[3]];
				i[3]++;
			}
			save[i[1]][i[3]] = '\0';
			i[1]++;
			i[0] += i[2];
			continue ;
		}
		i[0]++;
	}
}

int	ft_malloc_split(char **save, char const *s, char c)
{
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	if (save == 0 || s == 0)
		return (0);
	while (*(s + i[0]) != '\0')
	{
		i[2] = ft_strcount_nochr((s + i[0]), c);
		if (i[2] != 0)
		{
			save[i[1]] = (char *)malloc((i[2] + 1) * sizeof(char));
			if (save[i[1]] == 0)
				return (i[1] * -1);
			i[1]++;
			i[0] += i[2];
			continue ;
		}
		i[0]++;
	}
	return (1);
}

size_t	ft_strcount_nochr(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (*(s + i) != '\0' && *(s + i) != c)
		i++;
	return (i);
}

// to count how much strings to put in an array
unsigned int	ft_split_count(char const *s, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) != c && *(s + i) != '\0')
				i++;
		}
		if (*(s + i) != '\0')
			i++;
	}
	return (count);
}
