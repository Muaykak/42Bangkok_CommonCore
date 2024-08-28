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

size_t	ft_index_no_set(char const *s1, char const *set);
int		ft_check_isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	i;
	size_t	k;
	size_t	j;

	k = ft_index_no_set(s1, set);
	i = 0;
	while (ft_check_isset(*(s1 + i), set) == 1 && i < k)
		i++;
	if (i == k && ft_check_isset(*(s1 + i), set) == 1)
		temp = (char *)ft_calloc(1, sizeof(char));
	else
		temp = (char *)malloc(((k - i) + 2) * sizeof(char));
	if (temp == 0)
		return (0);
	j = 0;
	while (i + j <= k && i != k)
	{
		temp[j] = s1[i + j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

size_t	ft_index_no_set(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (ft_check_isset(*(s1 + i), set) == 1 && i != 0)
		i--;
	return (i);
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
