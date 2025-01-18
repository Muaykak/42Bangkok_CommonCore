/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_my_algor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:43:11 by srussame          #+#    #+#             */
/*   Updated: 2025/01/18 11:43:13 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MY_ALGOR_H
# define PUSH_SWAP_MY_ALGOR_H

# include "ft_push_swap.h"
# include "main_push_swap.h"

int		*check_stack_min_max(t_list *stack, int *num);
int		check_correct_order(t_list *stack_a, int min, int max);
void	my_algor_execute(t_list **stack_a, t_list **stack_b);

void	sorting_stack(t_list **stack_a, t_list **stack_b, int min, int max);
void	pivot_to_stack(t_list **stack_a, t_list **stack_b);
void	push_pivot(t_list **stack_a, t_list **stack_b, int min, int max);

#endif
