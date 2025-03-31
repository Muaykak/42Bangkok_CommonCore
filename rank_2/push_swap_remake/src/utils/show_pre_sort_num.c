/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_pre_sort_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:24:26 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 02:24:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	show_ps_num(t_list *list)
{
	if (list == NULL)
		return (0);
	return (((t_ps_node *)(list->content))->number);
}