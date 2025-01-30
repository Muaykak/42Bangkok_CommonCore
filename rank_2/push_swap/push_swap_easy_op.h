/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_easy_op.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:44:58 by srussame          #+#    #+#             */
/*   Updated: 2025/01/19 11:44:59 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_EASY_OP_H
# define PUSH_SWAP_EASY_OP_H

# include "ft_push_swap.h"
# include "main_push_swap.h"

void	easy_rotate(char c, t_list **stack, t_list *target, int print_op);
int 	(*decide_rotate_b(t_list *stack, t_list *target))
		(t_list **, t_list **, int);
int 	(*decide_rotate_a(t_list *stack, t_list *target))
		(t_list **, t_list **, int);
int		travese_dist(t_list *start, t_list *end);
void	easy_rotate_both(t_list **stack_a, t_list **stack_b,
		 t_list *target_a, t_list *target_b);

#endif
