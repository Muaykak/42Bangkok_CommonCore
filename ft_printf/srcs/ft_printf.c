/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:39:48 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 11:39:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_do_printf(const char *str, va_list args, int *count);
static int	ft_do_printf_sub1(const char *str, va_list args, int *count);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	if (ft_do_printf(str, args, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}

static int	ft_do_printf(const char *str, va_list args, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar_count(str[i], count);
		else
		{	
			i++;
			if (str[i] == '\0')
				return (-1);
//			ft_do_printf_sub1(&str[i], args, count);	
			if (ft_do_printf_sub1(&str[i], args, count) == 0)
			{
				ft_putchar_count('%', count);
			}
		}
		if (str[i] != '\0')
			i++;
	}
	return (i);
}

static int	ft_do_printf_sub1(const char *str, va_list args, int *count)
{

	if (*str == 'c')
		ft_putchar_count((char)va_arg(args, int), count);
	else if (*str == '%')
		ft_putchar_count('%', count);
	else if (*str == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_count(va_arg(args, int), count);
	else if (*str == 'p')
		ft_putaddress_count(va_arg(args, void *), count);
	else if (*str == 'x')
		ft_printf_puthex_small(va_arg(args, unsigned int), count);
	else if (*str == 'X')
		ft_printf_puthex_big(va_arg(args, unsigned int), count);
	else if (*str == 'u')
		ft_putuint_count(va_arg(args, unsigned int), count);
	else
		return (0);
	return (1);
}