/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:12:29 by srussame          #+#    #+#             */
/*   Updated: 2025/01/13 21:12:31 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

/* create a function to print all the list first*/
void	del_printed(size_t printed_size)
{
	size_t	i;

	i = 0;
	while (i < printed_size)
	{
		ft_printf("\b");
		i++;
	}
	i = 0;
	while (i++ < printed_size)
	{
		ft_printf(" ");
		i++;
	}
	i = 0;
	while (i++ < printed_size)
	{
		ft_printf("\b");
		i++;
	}
}

/* This function will print Both stack a and b*/
void	stack_display_overwrite(t_list *stack_a, t_list *stack_b)
{
	static size_t	printed_size;

	if (printed_size > 0)
	{
		del_printed(printed_size);
		printed_size = 0;
	}
	printed_size += ft_printf("A\t\tB\n\n");
	while (stack_a != 0 || stack_b != 0)
	{
		if (stack_a != 0)
			printed_size += ft_printf("%d", ((int *)stack_a->content)[0]);
		if (stack_b != 0)
			printed_size += ft_printf("\t\t%d", ((int *)stack_b->content)[0]);
		printed_size += ft_printf("\n");
		if (stack_a != 0)
			stack_a = stack_a->next;
		if (stack_b != 0)
			stack_b = stack_b->next;
	}
	printed_size += ft_printf("\n");
}

void	operation_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_stack_a;

	new_stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = new_stack_a;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*first_pos;

	ft_printf("hello\b\b\b\b\bworld\n");
	if (argc == 1)
	{
		ft_printf("atleast 1 argument to run the program.\n");
		return (0);
	}
	stack_a = put_argument(argc, argv);
	if (stack_a == 0)
		return (0);
	first_pos = stack_a;
	stack_b = 0;
	stack_display_overwrite(stack_a, stack_b);
	operation_push_b(&stack_a, &stack_b);
	stack_display_overwrite(stack_a, stack_b);
	ft_lstclear(&first_pos, &free_number);
}
