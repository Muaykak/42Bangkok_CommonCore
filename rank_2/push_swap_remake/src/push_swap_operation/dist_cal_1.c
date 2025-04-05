/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_cal_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:21:16 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 23:21:29 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			dist_cal(t_ps_node *start, t_ps_node *end);
int			dist_cal_rotate(t_ps_node *start, t_ps_node *end);
int			dist_cal_reverse(t_ps_node *start, t_ps_node *end);
static int	dist_cal_same_stack(t_ps_node *start, t_ps_node *end);
static int	dist_cal_diff_stack(t_ps_node *start, t_ps_node *end);

int	dist_cal(t_ps_node *start, t_ps_node *end)
{
	int	dist;

	if (start == NULL || end == NULL || start == end)
		return (0);
	if (start->stack->stack == end->stack->stack)
		dist = dist_cal_same_stack(start, end);
	else
		dist = dist_cal_diff_stack(start, end);
	return (dist);
}

int	dist_cal_reverse(t_ps_node *start, t_ps_node *end)
{
	if (start == NULL || end == NULL || start == end)
		return (0);
	return (start->stack->size - dist_cal_rotate(start, end));
}

int	dist_cal_rotate(t_ps_node *start, t_ps_node *end)
{
	int	dist;

	if (start == NULL || end == NULL || start == end)
		return (0);
	if (start->stack_pos > end->stack_pos)
		dist = start->stack_pos - end->stack_pos;
	else
		dist = start->stack->size - start->stack_pos + end->stack_pos;
	return (dist);
}

static int	dist_cal_same_stack(t_ps_node *start, t_ps_node *end)
{
	int	dist;
	int	dist1;

	dist = dist_cal_rotate(start, end);
	dist1 = dist_cal_reverse(start, end);
	if (dist1 < dist)
		dist = dist1;
	return (dist);
}

static int	dist_cal_diff_stack(t_ps_node *start, t_ps_node *end)
{
	int	dist_rotate;
	int	dist_reverse;
	int	temp;

	dist_rotate = dist_cal_rotate(start, start->stack->top);
	temp = dist_cal_rotate(end, end->stack->top);
	if (temp > dist_rotate)
		dist_rotate = temp;
	dist_reverse = dist_cal_reverse(start, start->stack->top);
	temp = dist_cal_reverse(end, end->stack->top);
	if (temp > dist_reverse)
		dist_reverse = temp;
	if (dist_reverse < dist_rotate)
		return (dist_reverse);
	return (dist_rotate);
}
