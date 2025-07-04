/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:56:17 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 16:57:21 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*temp;

	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof (char));
	if (temp == 0)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(temp + i) = *(s + i);
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
