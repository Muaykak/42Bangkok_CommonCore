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

# include "../libft/include/libft.h"
# include "ft_push_swap_utils.h"
# include "push_swap_easy_op.h"

int		check_format(int argc, char **argv);
int		check_format_sub1(char *argv, int j);
int		check_int_limit(char *num_set);
t_list	*put_argument(int argc, char **argv);
int		put_argument_sub1(t_list **stack_a, int **number, char **num_set);
int		put_argument_sub2(t_list **stack_a, int argc, char **argv);
int		dup_check(t_list *stack);

int		check_stack_sorted(t_list *stack_a);

int		op_push_b(t_list **stack, t_list **push, int print_op);
int		op_swap_b(t_list **unused, t_list **stack, int print_op);
int		op_swap_a(t_list **stack, t_list **unused, int print_op);
int		op_swap_all(t_list **stack_a, t_list **stack_b, int print_op);
int		op_rotate_b(t_list **unused, t_list **stack, int print_op);
int		op_rotate_a(t_list **unused, t_list **stack, int print_op);
int		op_reverse_a(t_list **stack, t_list **unused, int print_op);
int		op_rotate_all(t_list **stack_a, t_list **stack_b, int print_op);
int		op_reverse_b(t_list **unused, t_list **stack, int print_op);
int		op_reverse_all(t_list **stack_a, t_list **stack_b, int print_op);
int		op_push_a(t_list **push, t_list **stack, int print_op);

#endif