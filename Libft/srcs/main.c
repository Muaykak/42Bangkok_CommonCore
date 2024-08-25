/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:48:59 by srussame          #+#    #+#             */
/*   Updated: 2024/08/24 14:27:06 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	/*
	char	c = 'a'
	printf("ft_isalpha Return: %d\n", ft_isalpha(c));
	printf("isalpha Return: %d\n", isalpha(c))
	*/
//	printf("ft_isdigit Return: %d\n", ft_isdigit('b'));
//	printf("ft_isalnum Return: %d\n", ft_isalnum('c'));
//	printf("ft_isascii Return: %d\n", ft_isascii('d'));
//	printf("ft_isprint Return: %d\n", ft_isprint('e'));
//	printf("ft_strlen Return: %lu\n", ft_strlen(""));

	/*
//	ft_memset
	int	arr[20];

	ft_memset(arr, 0, 20 * sizeof(arr[0]));
	int	i = 0;
	while (i < 20)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		if(i < 10)
			i++;
		else
			break ;
	}
	*/

	/*
//	ft_bzero
	int	k = 10;
	int	arr[k];

	ft_bzero(&arr[0], k * sizeof(arr[0]));
	int	i = 0;
	while (i < k)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;		
	}
	*/

	/*
//	ft_memcpy and ft_memmove
	char	str2[20] = "abcdefghijklmnop";
	printf("Stelen count: %lu\n", strlen(str2));
	printf("Sizeof str2: %lu\n", sizeof(str2));
	printf("str2 before memcpy: %s\n", str2);
	ft_memmove(str2 + 5, str2, 7);
	printf("str2 after memcpy: %s\n", str2);
	return (0);
	*/

//	ft_strlcpy
	char	dest[20] = "Hello";
	char	src[20] = "hi";
	printf("The dest string: %s\n", dest);
	printf("The src string: %s\n", dest);
	strlcpy(dest, src, 1);
	printf("Dest after strlcpy: %s\n", dest);
}
