/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:28:57 by muaykak           #+#    #+#             */
/*   Updated: 2024/09/24 18:09:55 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\nPrintf: %d\n", printf("%p\n", "hello"));
	ft_printf("\nft_Printf: %d\n", ft_printf("%p\n", "hello"));
}
