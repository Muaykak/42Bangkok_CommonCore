/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:56:21 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 21:17:53 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (unsigned char)c)
			ptr = (char *)(s + i);
		i++;
	}
	if (*(s + i) == '\0' && (unsigned char)c == '\0')
		return ((char *)(s + i));
	else
		return (ptr);
}
