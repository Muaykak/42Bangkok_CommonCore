/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:54:37 by muaykak           #+#    #+#             */
/*   Updated: 2024/11/09 05:49:43 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
        int ret = 0;
        ret = pause();
        ft_printf("Pause returned with %d\n", ret);
        return 0;
}


