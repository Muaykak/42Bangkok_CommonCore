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
#include <stdlib.h>
#include "libft.h"

int	main(int ac, char **av)
{
	/*
	(void)ac;
	(void)av;
	char	c = 'a'
	printf("ft_isalpha Return: %d\n", ft_isalpha(c));
	printf("isalpha Return: %d\n", isalpha(c))
	*/
	
	/*
	(void)ac;
	(void)av;
//	printf("ft_isdigit Return: %d\n", ft_isdigit('b'));
//	printf("ft_isalnum Return: %d\n", ft_isalnum('c'));
//	printf("ft_isascii Return: %d\n", ft_isascii('d'));
//	printf("ft_isprint Return: %d\n", ft_isprint('e'));
//	printf("ft_toupper Return: %d\n", ft_toupper('k'));
//	printf("ft_tolower Return: %d\n", ft_tolower('k'));
//	printf("ft_strlen Return: %lu\n", ft_strlen(""));
	*/

	/*
//	ft_memset
	int	arr[20];

	(void)ac;
	(void)av;
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

	(void)ac;
	(void)av;
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

	(void)ac;
	(void)av;
	printf("Stelen count: %lu\n", strlen(str2));
	printf("Sizeof str2: %lu\n", sizeof(str2));
	printf("str2 before memcpy: %s\n", str2);
	ft_memmove(str2 + 5, str2, 7);
	printf("str2 after memcpy: %s\n", str2);
	return (0);
	*/

	/*	
//	ft_strlcpy
	(void)ac;
	(void)av; 
	char	dest[20] = "";
	char	src[20] = "";
	size_t	return_value;
	printf("The dest string: %s\n", dest);
	printf("The src string: %s\n", src);
	return_value = ft_strlcpy(dest, src, 3);
	printf("Dest after strlcpy: %s\n", dest);
	printf("Return value: %lu\n", return_value);
	*/

	/*
//	ft_strlcat
	char	dest[7] = "";
	char	src[20] = "";
	size_t	return_value;

	(void)ac;
	(void)av;
	printf("The dest string: %s\n", dest);
	printf("The src string: %s\n", src);
	return_value = ft_strlcat(dest, src, 6);
	printf("Dest after strlcat: %s\n", dest);
	printf("Return value: %lu\n", return_value);
	*/

	/*
//	ft_strchr
	char	str[] = "Hello";
	char	c = 'H';
	char	*ptr;

	(void)ac;
	(void)av;
	printf("the string: %s\n", str);
	ptr = ft_strchr(str, c);
	printf("chr: %c\nptr: %s\n", c, ptr);
	*/

	/*
//	ft_strrchr
	char	str[] = "Hello";
	char	c = 'z';
	char	*ptr;

	(void)ac;
	(void)av;
	printf("the string: %s\n", str);
	ptr = ft_strrchr(str, c);
	printf("chr: %c\nptr: %s\n", c, ptr);
	*/

	/*
//	ft_strncmp
	char	s1[] = "Hello";
	char	s2[] = "Hellq";

	(void)ac;
	(void)av;
	printf("str1: %s\n", s1);
	printf("str2: %s\n", s2);
	printf("ft_strncmp return: %d\n", strncmp(s1, s2, 5));
	*/

	/*
//	ft_memchr
	char	str[] = "Hello";
	char	c = 'k';
	void	*ptr;

	(void)ac;
	(void)av;
	printf("String: %s\n", str);
	printf ("character: %c\n", c);
	ptr = ft_memchr(str, c, 11);
	printf ("ptr: %s\n", (char *)ptr);
	*/

	/*
//	ft_memcmp
	char	str1[] = "Hello";
	char	str2[] = "Hello";
	int		return_value;

	(void)ac;
	(void)av;
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	return_value = ft_memcmp(str1, str2, 2);
	printf("ft_memcmp return value: %d\n", return_value);
	*/

	/*
//	ft_strnstr
	char	big[] = "Hello my name is mark the 42 cadet";
	char	little[] = "";
	char	*ptr;

	if (ac != 2)
		return (0);
	printf("The big string: %s\n", big);
	printf("The little string: %s\n", little);
	ptr = strnstr(big, little, atoi(av[1]));
	printf("ptr: %s\n", ptr);
	*/

	/*
//	ft_atoi
	if (ac != 2)
		return (0);
	printf("The argument is: %s\n", av[1]);
	printf("ft_atoi = %d\n", atoi(av[1]));
	*/
	
	/*
//	ft_strdup
	char	*ptr;

	if (ac != 2)
		return (0);
	printf("The argument: %s\n", av[1]);
	printf("pos: %p\n", &av[1]);
	ptr = ft_strdup(av[1]);
	printf("ptr: %s\n", ptr);
	printf("pos: %p\n", &ptr);
	free(ptr);
	*/

	/*
//	ft_calloc
	int	*arr;
	int	i;

	if (ac != 2)
		return (0);
	arr = (int *)calloc(atoi(av[1]), sizeof(int));
	if (arr == 0)
	{
		printf("calloc failed\n");
		return (1);
	}
	i = 0;
	while (i < atoi(av[1]))
	{
		printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
	*/

	/*
//	ft_substr
	char	str[] = "Hello Vsauce Michael here :)";
	char	*sub;

	if (ac != 3)
		return (1);
	printf("String: %s\n", str);
	sub = ft_substr(str, atoi(av[1]), atoi(av[2]));
	if (sub == 0)
	{
		printf("Allocation Failed.\n");
		return (1);
	}
	printf("sub: \"%s\"\n", sub);
	printf("index: %d\n", atoi(av[1]));
	printf("length: %lu\n", ft_strlen(sub));
	return (0);
	*/

	/*
//	ft_strjoin
	char	*cat;

	if (ac != 3)
		return (1);
	printf("str1: \"%s\"\n", av[1]);
	printf("str2: \"%s\"\n", av[2]);
	cat = ft_strjoin(av[1], av[2]);
	if (cat == 0)
	{
		printf ("Alloc Failed.\n");
		return (1);
	}
	printf("cat string: \"%s\"\n", cat);
	return (0);
	*/

	/*	
//	ft_strtrim
	char	*trim;

	if (ac != 3)
		return (1);
	printf("str: \"%s\"\n", av[1]);
	printf("set: \"%s\"\n", av[2]);
	trim = ft_strtrim(av[1], av[2]);
	if (trim == 0)
	{
			printf("Alloc failed.\n");
			return (1);
	}
	printf("trim: \"%s\"\n", trim);
	return (0);
	*/	

	/*		
//	ft_split
	char	**save;
	int		i;
//	size_t	n;

	if (ac != 3)
		return (1);
	printf("str1: \"%s\"\n", av[1]);
	printf("character: \'%c\'\n", av[2][0]);
	save = ft_split(av[1], av[2][0]);
	if (save == 0)
	{
		printf("Alloc error.\n");
		return (1);
	}
	i = 0;
	while (save[i] != 0)
	{
		printf("save[%d]: \"%s\"\n", i, save[i]);
		i++;
	}

	
	n = ft_split_count(av[1], av[2][0]);
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
	*/
	

		
//	ft_itoa
	int	n;
	char	*save;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	printf("the number: %d\n", n);
	save = ft_itoa(n);
	printf("itoa: \"%s\"\n", save);
	return (0);
		

	/*
//	ft_strmapi
	char	*save;

	if (ac != 2)
		return (1);
	printf("str: \"%s\"\n", av[1]);
	save = ft_strmapi(av[1], &ft_changetoa);
	printf("ft_strmapi: \"%s\"\n", save);
	return (0);
	*/

	/*
//	ft_putstr_fd
	if (ac != 2)
		return (1);
	ft_putstr_fd("The argument: ", 1);
	ft_putstr_fd(av[1], 1);
	ft_putstr_fd("\n", 1);
	return (0);
	*/

	/*
//	ft_putendl_fd
	if(ac != 2)
		return (1);
	ft_putendl_fd(av[1], 1);
	return (0);
	*/

	/*
//	ft_putnbr_fd
	if(ac != 2)
		return (1);
	ft_putnbr_fd(atoi(av[1]), 1);
	return (0);
	*/

	/*
//	test

//	(void)ac;
//	(void)av;
	if (ac != 3)
		return (0);
	printf("%d to the power of %d is %d\n", atoi(av[1]), atoi(av[2]), ft_power(atoi(av[1]), atoi(av[2])));
//	printf("ft_isspace: %d\n", ft_isspace(' '));
	*/
}
