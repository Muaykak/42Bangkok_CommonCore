/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:27:11 by srussame          #+#    #+#             */
/*   Updated: 2024/08/25 15:27:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest > src)
	{
		n--;
		while (n > 0)
		{
			*((char *)(dest + n)) = *((char *)(src + n));
			n--;
		}
		*((char *)(dest + n)) = *((char *)(src + n));
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((char *)(dest + i)) = *((char *)(src + i));
			i++;
		}
	}
	return (dest);
}
