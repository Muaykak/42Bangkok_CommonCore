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

int		count_digit(int n);
void	ft_itoa_positive(char *temp, int n, int m);
void	ft_itoa_negative(char *temp, int n, int m);

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
	if (n < 0)
		ft_itoa_negative(temp, n, m);
	else
		ft_itoa_positive(temp, n, m);
	return (temp);
}

void	ft_itoa_negative(char *temp, int n, int m)
{
	temp[0] = '-';
	n = n * -1;
	if (n < -2147483647)
	{
		ft_strlcpy(temp, "-2147483648", 12);
		return ;
	}
	while (m-- > 1)
	{
		temp[m] = (n % 10) + 48;
		n = n / 10;
	}
}

void	ft_itoa_positive(char *temp, int n, int m)
{
	while (m-- > 0)
	{
		temp[m] = (n % 10) + 48;
		n = n / 10;
	}
	temp[m] = (n % 10) + 48;
}

int	count_digit(int n)
{
	int	count;

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
