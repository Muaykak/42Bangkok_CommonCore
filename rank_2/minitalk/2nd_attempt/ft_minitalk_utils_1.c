/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:02:44 by srussame          #+#    #+#             */
/*   Updated: 2024/11/29 14:02:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	bintext_init(char *str);
int		bin_to_decimal(char *bin);
int		ft_power(int x, int pow);
int		ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_power(int x, int pow)
{
	int	result;

	if (pow < 0)
		return (0);
	result = 1;
	while (pow > 0)
	{
		result = result * x;
		pow--;
	}
	return (result);
}

int	bin_to_decimal(char *bin)
{
	int	bin_num;
	int	dec_num;
	int	n;

	bin_num = ft_atoi(&bin[1]);
	dec_num = 0;
	n = 0;
	if (ft_strcmp(bin, "10000000") == 0)
		return (-128);
	while (bin_num / 10 != 0 || bin_num != 0)
	{
		dec_num += (bin_num % 10) * (ft_power(2, n));
		n++;
		bin_num /= 10;
	}
	if (bin[0] == '1')
		dec_num *= -1;
	return (dec_num);
}

void	bintext_init(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i <= 8)
	{
		str[i] = '\0';
		i++;
	}
}
