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


int main(int argc, char **argv)
{
	int	i;
	int	*number;
	t_list	*stack_a;
	t_list	*first_pos;
	char **num_set;

	if (argc != 2)
		return (0);
	num_set = ft_split(argv[1], ' ');
	i = 0;
	while (num_set[i] != 0)
	{
		number = (int *)malloc(sizeof(int));
		if (number == NULL)
			return (0);
		number[0] = ft_atol(num_set[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(&number[0]));
		i++;
	}
	i = 1;
	first_pos = stack_a;
	while (stack_a->next != 0)
	{
		ft_printf("Element[%d]: %d\n", i, *((int *)(stack_a->content)));
		stack_a = stack_a->next;
		i++;
	}
	ft_printf("Element[%d]: %d\n", i, *((int *)(stack_a->content)));
	ft_lstclear(&first_pos, &free_number);
}
