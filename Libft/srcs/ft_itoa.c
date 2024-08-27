/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:54:03 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 16:54:03 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(int n);

char	*ft_itoa(int n)
{
	int		m;
	char	*temp;

	m = count_digit(n);
	if (n < 0)
		m += 1;
	temp = (char *)malloc((m + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	temp[m] = '\0';
	while (m-- > 0)
	{
		temp[m] = (n % 10) + 48;
		n = n / 10;
	}
	temp[m] = (n % 10) + 48;
	return (temp);
}

int	count_digit(int n)
{
	int count;

	count = 1;
	if (n < 0)
		n = -1 * n;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
