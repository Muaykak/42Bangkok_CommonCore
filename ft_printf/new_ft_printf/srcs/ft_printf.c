/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:02:06 by srussame          #+#    #+#             */
/*   Updated: 2024/09/24 18:23:53 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_do_printf_sub1(const char *str, va_list args, int *count);
static int	ft_do_printf(const char *str, va_list args, int *count);

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
	int sub1_ret;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			if (ft_putchar_count(str[i], count) == 0)
				return (-1);
		}
		else
		{	
			i++;
			sub1_ret = ft_do_printf_sub1(&str[i], args, count);
			if (sub1_ret == 0)
			{
				if (str[i] == '\0')
					return (-1);
				if (ft_putchar_count('%', count) == 0)
					return (-1);
				if (ft_putchar_count(str[i], count) == 0)
					return (-1);
			}
			else if (sub1_ret == -1)
				return (-1);
		}
		if (str[i] != '\0')
			i++;
	}
	return (*count);
}

static int	ft_do_printf_sub1(const char *str, va_list args, int *count)
{

	if (*str == 'c')
	{
		if (ft_putchar_count((char)va_arg(args, int), count) == 0)
			return (-1);
	}
	else if (*str == '%')
	{
		if (ft_putchar_count('%', count) == 0)
			return (-1);
	}
	else if (*str == 's')
	{
		if (ft_putstr_count(va_arg(args, char *), count) == 0)
			return (-1);
	}
	else if (*str == 'd' || *str == 'i')
	{
		if (ft_putnbr_count(va_arg(args, int), count) == 0)
			return (-1);
	}
	else if (*str == 'p')
	{
		if (ft_putaddress_count(va_arg(args, void *), count) == 0)
			return (-1);
	}
	else if (*str == 'x')
	{
		if (ft_puthex_small_count(va_arg(args, unsigned int), count) == 0)
			return (-1);
	}
	else if (*str == 'X')
	{
		if (ft_puthex_big_count(va_arg(args, unsigned int), count) == 0)
			return (-1);
	}
	else if (*str == 'u')
	{
		if (ft_putuint_count(va_arg(args, unsigned int), count) == 0)
			return (-1);
	}
	else
		return (0);
	return (1);
}
