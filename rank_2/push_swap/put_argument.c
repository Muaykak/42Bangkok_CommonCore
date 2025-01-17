/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:19:27 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 10:19:30 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		check_format_sub1(char *argv, int j);
int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);
/* ************* Main Function ************************* */
t_list	*put_argument(int argc, char **argv);
/* ***************************************************** */
int		put_argument_sub1(t_list **stack_a, int **number, char **num_set);

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
	char	**num_set;
	int		*number;
	int		i;

	if (check_format(argc, argv) == 0)
		return (NULL);
	i = 1;
	stack_a = 0;
	while (argc > i)
	{
		num_set = ft_split(argv[i], ' ');
		if (num_set == 0)
		{
			if (stack_a != 0)
				ft_lstclear(&stack_a, &free_number);
			return (NULL);
		}
		if (put_argument_sub1(&stack_a, &number, num_set) == 0)
			return (NULL);
		ft_free_split(num_set);
		i++;
	}
	return (stack_a);
}

/*sub function of check_format*/
int	check_format_sub1(char *argv, int j)
{
	if ((argv[j] < '0' || argv[j] > '9' ) && argv[j] != '-' \
	&& argv[j] != '+' && argv[j] != ' ')
		return (0);
	if (argv[j] == '+' || argv[j] == '-')
	{
		if (j != 0 && argv[j - 1] != ' ')
			return (0);
		if (argv[j + 1] < '0' || argv[j + 1] > '9')
			return (0);
	}
	return (1);
}

/* This is sub function to check the cjorrect format
	Will check various things through its sub functions*/
int	check_format(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argc > i)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (check_format_sub1(argv[i], j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* check if the splitted string has the number in range
		-2147483648 to 2147483647*/
int	check_int_limit(char *num_set)
{
	size_t	i;
	long	num;

	i = 0;
	while (num_set[i] != 0)
		i++;
	if (i > 11)
		return (0);
	num = ft_atol(num_set);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	else
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
