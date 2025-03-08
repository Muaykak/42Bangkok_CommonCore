/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_easy_op_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:56:17 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 21:56:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_easy_op.h"

int		travese_dist(t_list *start, t_list *end);
int		traverse_dist_both(t_list *top_a, t_list *target_a,
			t_list *top_b, t_list *target_b);
int		trav_top(t_list *start, t_list *end);
int		trav_bot(t_list *start, t_list *end);

int	travese_dist(t_list *start, t_list *end)
{
	int		i;
	t_list	*top;

	i = 0;
	if (!start || !end)
		return (i);
	top = start;
	while (start != 0 && start != end)
	{
		start = start->next;
		i++;
	}
	if ((ft_lstsize(top) + 1) / 2 > i)
		return (i);
	else
		return (ft_lstsize(top) - i);
}

int	traverse_dist_both(t_list *top_a, t_list *target_a,
		t_list *top_b, t_list *target_b)
{
	int	result[4];

	if (!top_a || !top_b || !target_a || !target_b)
		return (0);
	result[0] = trav_top(top_a, target_a);
	if (trav_top(top_b, target_b) > result[0])
		result[0] = trav_top(top_b, target_b);
	result[1] = trav_bot(top_a, target_a);
	if (trav_bot(top_b, target_b) > result[1])
		result[1] = trav_bot(top_b, target_b);
	result[2] = travese_dist(top_a, target_a) + travese_dist(top_b, target_b);
	result[3] = result[0];
	if (result[1] < result[3])
		result[3] = result[1];
	if (result[2] < result[3])
		result[3] = result[2];
	return (result[3]);
}

int	trav_top(t_list *start, t_list *end)
{
	int	i;

	if (!start || !end)
		return (0);
	i = 0;
	while (start && start != end)
	{
		start = start->next;
		i++;
	}
	return (i);
}

int	trav_bot(t_list *start, t_list *end)
{
	return (ft_lstsize(start) - trav_top(start, end));
}
