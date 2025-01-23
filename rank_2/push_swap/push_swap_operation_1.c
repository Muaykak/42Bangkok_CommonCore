/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:23 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 14:07:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "main_checker.h"
#include "main_push_swap.h"

static void	op_handler_sub1(t_list **stack_a, t_list **stack_b,\
			 char *command, int print_op);
void		op_handler(t_list **stack_a, t_list **stack_b,\
			 char *command, int print_op);
int			op_push(t_list **push, t_list **stack);
int			op_reverse(t_list **stack);
int			op_rotate(t_list **stack);


static void	op_handler_sub1(t_list **stack_a, t_list **stack_b,\
			 char *command, int print_op)
{
	if (ft_strncmp(command, "sb", 2) == 0 && op_swap(stack_b) == 0)
			return ;
	else if (ft_strncmp(command, "ss", 2) == 0)
	{
		if ((*stack_a) == 0 || (*stack_b) == 0 || \
		op_swap(stack_a)  == 0 || op_swap(stack_b) == 0 )
			return ;
	}
	else if (ft_strncmp(command, "rra", 3 ) == 0 && op_reverse(stack_a) == 0)
			return ;
	else if (ft_strncmp(command, "rrb", 3 ) == 0 && op_reverse(stack_b) == 0)
			return ;
	else if (ft_strncmp(command, "rrr", 3) == 0)
	{
		if ((*stack_a) == 0 || (*stack_b) == 0 || \
		op_reverse(stack_a)  == 0 || op_reverse(stack_b) == 0 )
			return ;
	}
	if (print_op == 1)
		ft_printf("%s\n", command);
}


void	op_handler(t_list **stack_a, t_list **stack_b,\
		 char *command, int print_op)
{
	if (!stack_a || !stack_b || !command || ft_strlen(command) < 2)
		return ;
	if (ft_strncmp(command, "pa", 2) == 0 && op_push(stack_a, stack_b) == 0)
			return ;
	else if (ft_strncmp(command, "pb", 2) == 0 && op_push(stack_b, stack_a) == 0)
			return ;
	else if (ft_strncmp(command, "ra", 2) == 0 && op_rotate(stack_a) == 0)
			return ;
	else if (ft_strncmp(command, "rb" ,2) == 0 && op_rotate(stack_b) == 0)
			return ;
	else if (ft_strncmp(command, "rr\0", 3) == 0)
	{
		if ((*stack_a) == 0 || (*stack_b) == 0 \
		|| op_rotate(stack_a)  == 0 || op_rotate(stack_b) == 0 )
			return ;
	}
	else if (ft_strncmp(command, "sa", 2) == 0 && op_swap(stack_a) == 0)
			return ;
	op_handler_sub1(stack_a, stack_b, command, print_op);
}

int	op_push(t_list **push, t_list **stack)
{
	t_list	*new;

	if (!push || !stack || (*stack) == 0)
		return (0);
	new = *stack;
	*stack = (*stack)->next;
	ft_lstadd_front(push, new);
	return (1);
}

int	op_reverse(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack);
	while (temp->next->next != 0)
		temp = temp->next;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	temp->next = 0;
	return (1);
}

int	op_rotate(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = 0;
	*stack = temp;
	return (1);
}