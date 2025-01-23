/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:41:51 by muaykak           #+#    #+#             */
/*   Updated: 2024/11/05 08:55:24 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "ft_push_swap_utils.h"
# include "push_swap_easy_op.h"

int		check_format_sub1(char *argv, int j);
int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);
t_list	*put_argument(int argc, char **argv); //Main function
int		put_argument_sub1(t_list **stack_a, int **number, char **num_set);

int		check_stack_sorted(t_list *stack_a, t_list *stack_b);

void	op_handler(t_list **stack_a, t_list **stack_b,\
		 char *command, int print_op);
int		op_swap(t_list **stack);
int		op_push(t_list **push, t_list **stack);
int		op_reverse(t_list **stack);
int		op_rotate(t_list **stack);

#endif