/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:31:17 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 11:31:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_no_set(char const *s1, char const *set);
int		ft_check_isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	i;
	size_t	k;

	temp = (char *)malloc((ft_count_no_set(s1, set) + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	i = 0;
	k = 0;
	while (*(s1 + i) != '\0')
	{
		if (ft_check_isset(*(s1 + i), set) == 1)
		{
			i++;
			continue ;
		}
		*(temp + k) = *(s1 + i);
		k++;
		i++;
	}
	*(temp + k) = '\0';
	return (temp);
}

size_t	ft_count_no_set(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*(s1 + i) != '\0')
	{
		if (ft_check_isset(*(s1 + i), set) == 0)
			count++;
		i++;
	}
	return (count);
}

int	ft_check_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}
