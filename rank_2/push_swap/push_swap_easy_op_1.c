/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_easy_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:44:20 by srussame          #+#    #+#             */
/*   Updated: 2025/01/19 11:44:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_easy_op.h"

/* calculate the distance */
/* have to be on the same stack*/
int	travese_dist(t_list *start, t_list *end)
{
	int i;
	
	i = 0;
	if (!start || !end)
		return (i);
	while (start != 0 && start != end)
	{
		start = start->next;
		i++;
	}
	if ((ft_lstsize(start) + 1) / 2 > i)
		return (i);
	else
		return (ft_lstsize(start) - i);
}

/* decide to rotate or reverse rotate to that target*/
int (*decide_rotate(t_list *stack, t_list *target))(t_list **)
{
	int 	i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (stack != target)
	{
		i++;
		stack = stack->next;
	}
	stack = temp;
	if (i > ((ft_lstsize(stack) + 1) / 2))
		return (&op_reverse);
	else
		return (&op_rotate);
}

/* rotate the stack until the top of the stack is the same as target*/
void	easy_rotate(char c, t_list **stack, t_list *target, int print_op)
{
	int		(*decider)(t_list **);
	char	command[4];

	if (*stack == target || (*stack)->next == 0)
		return ;
	decider = decide_rotate(*stack, target);
	command[0] = 'r';
	if (decider == &op_rotate)
	{
		command[1] = c;
		command[2] = '\0';
	}
	else if (decider == &op_reverse)
	{
		command[1] = 'r';
		command[2] = c;
		command[3] = '\0';
	}
	while ((*stack) != target)
		op_handler(stack, stack, command, print_op);
}
