/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:26:09 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 17:26:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putuint_count(unsigned int num, int *count)
{
	if (num / 10 != 0)
		ft_putuint_count((num / 10), count);
	ft_putchar_count((char)((num % 10) + 48), count);
}
