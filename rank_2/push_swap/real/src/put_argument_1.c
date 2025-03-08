/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_argument_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:22:14 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 22:22:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************* Main Function ************************* */
t_list	*put_argument(int argc, char **argv);
/* ***************************************************** */
int		dup_check(t_list *stack);
int		put_argument_sub1(t_list **stack_a, int **number, char **num_set);
int		put_argument_sub2(t_list **stack_a, int argc, char **argv);

int	put_argument_sub2(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	**num_set;
	int		*number;

	i = 1;
	*stack_a = 0;
	while (argc > i)
	{
		num_set = ft_split(argv[i], ' ');
		if (num_set == 0)
		{
			if (*stack_a != 0)
				ft_lstclear(stack_a, &free_number);
			return (0);
		}
		if (put_argument_sub1(stack_a, &number, num_set) == 0)
			return (0);
		ft_free_split(num_set);
		i++;
	}
	return (1);
}
/* This function is to check the given argument
	whether they have the correct format

		the correct format is
		1. Each argument must contains only [1-9] and ['-', or '+']
		2. each NUMBER in the argument (or in each argument
			MUST be separated by SPACE(ascii 32)
		3. both positive and negative value can be entered
			BUT MUST BE in integer range
				-2147483648 to 2147483647
		4. The program will correctly executed
			if ONLY ALL THE ARGUMENTS are in correct format
			as mentioned above

	**** After checking all the numbers, this function will return
	**** A list of numbers which is "Stack A" ****
	**********************************************. */

t_list	*put_argument(int argc, char **argv)
{
	t_list	*stack_a;

	if (check_format(argc, argv) == 0)
		return (NULL);
	put_argument_sub2(&stack_a, argc, argv);
	if (dup_check(stack_a) == 1)
		return (stack_a);
	ft_lstclear(&stack_a, &free_number);
	return (0);
}

/* function to check duplicate*/
// int	dup_check(t_list *stack)
// {
// 	t_list	*temp;

// 	if (!stack)
// 		return (0);
// 	temp = stack;
// 	while (stack != 0)
// 	{
// 		stack = stack->next;
// 		while (stack != 0)
// 		{
// 			if (show_int(temp) == show_int(stack))
// 				return (0);
// 			stack = stack->next;
// 		}
// 		if (temp->next != 0)
// 			temp = temp->next;
// 		if (temp->next != 0)
// 			stack = temp->next;
// 	}
// 	return (1);
// }
int	dup_check(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp != NULL)
	{
		stack = temp->next;
		while (stack != NULL)
		{
			if (show_int(temp) == show_int(stack))
				return (0);
			stack = stack->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	put_argument_sub1(t_list **stack_a, int **number, char **num_set)
{
	int	j;

	j = 0;
	while (num_set[j] != 0)
	{
		*number = (int *)malloc(sizeof(int));
		if (*number == 0)
		{
			ft_free_split(num_set);
			return (0);
		}
		if (check_int_limit(num_set[j]) == 0)
		{
			free(*number);
			ft_free_split(num_set);
			if (*stack_a != 0)
				ft_lstclear(stack_a, &free_number);
			return (0);
		}
		(*number)[0] = ft_atol(num_set[j]);
		ft_lstadd_back(stack_a, ft_lstnew(&(*number[0])));
		j++;
	}
	return (1);
}
