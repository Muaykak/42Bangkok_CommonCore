/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:02:06 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 20:10:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_do_printf_sub1(const char *str, va_list args, t_ft_printf *data);
static int	ft_do_printf_sub2(const char *str, va_list args, t_ft_printf *data, int i);
static int	ft_do_printf(const char *str, va_list args, t_ft_printf *data);

int	ft_printf(int fd, const char *str, ...)
{
	va_list		args;
	t_ft_printf	data;

	if (!str)
		return (-1);
	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	data.count = 0;
	data.fd = fd;
	va_start(args, str);
	if (ft_do_printf(str, args, &data) == -1)
		return (-1);
	va_end(args);
	return (data.count);
}

static int	ft_do_printf(const char *str, va_list args, t_ft_printf *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			if (ft_putchar_count(str[i], data) == -1)
				return (-1);
		}
		else
		{
			i++;
			if (ft_do_printf_sub2(str, args, data, i) == -1)
				return (-1);
		}
		if (str[i] != '\0')
			i++;
	}
	return (data->count);
}

static int	ft_do_printf_sub2(const char *str, va_list args, t_ft_printf *data, int i)
{
	int	sub1_ret;

	sub1_ret = ft_do_printf_sub1(&str[i], args, data);
	if (sub1_ret == 0)
	{
		if (str[i] == '\0')
			return (-1);
		if (ft_putchar_count('%', data) == 0)
			return (-1);
		if (ft_putchar_count(str[i], data) == 0)
			return (-1);
	}
	else if (sub1_ret == -1)
		return (-1);
	return (1);
}

static int	ft_do_printf_sub1(const char *str, va_list args, t_ft_printf *data)
{
	if (*str == 'c')
		return (ft_putchar_count((char)va_arg(args, int), data));
	else if (*str == '%')
		return (ft_putchar_count('%', data));
	else if (*str == 's')
		return (ft_putstr_count(va_arg(args, char *), data));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_count(va_arg(args, int), data));
	else if (*str == 'p')
		return (ft_putaddress_count(va_arg(args, void *), data));
	else if (*str == 'x')
		return (ft_puthex_small_count(va_arg(args, unsigned int), data));
	else if (*str == 'X')
		return (ft_puthex_big_count(va_arg(args, unsigned int), data));
	else if (*str == 'u')
		return (ft_putuint_count(va_arg(args, unsigned int), data));
	else
		return (0);
}
