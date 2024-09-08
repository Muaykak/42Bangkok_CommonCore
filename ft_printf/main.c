/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:31:25 by srussame          #+#    #+#             */
/*   Updated: 2024/09/07 17:31:27 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int	main(void)
{
	int	count = 0;

//	ft_putstr_count("Helllooooo", &count);
//	printf("\ncount: %d\n", count);

	/* Check %c*/
//	char c;
//
//	while (c != 0)
//	{
//		printf("|| %c ", c);
//		c++;
//	}

	ft_printf("\nFT_PRINTF\n");
	ft_printf("\nReturn ft_printf || %d ||\n", ft_printf("%\nkd%"));

	printf("\nPRINTF\n");
	printf("\nReturn printf || %d ||\n", printf("%\nkd%"));
}