/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_forth_algor.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:04:22 by srussame          #+#    #+#             */
/*   Updated: 2025/01/27 15:04:24 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_FORTH_ALGOR_H
# define PUSH_SWAP_FORTH_ALGOR_H

# include "ft_push_swap.h"

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE 4
# endif

void	cost_algor(t_list **stack_a, t_list **stack_b);
int		move_to_b(t_list **stack_a, t_list **stack_b,
			t_list *fake_list);
t_list	*find_closest_value(t_list *stack_a, t_list *to_find);
void	cost_algor(t_list **stack_a, t_list **stack_b);
t_list	*find_to_push_a(t_list *stack_a, t_list *stack_b,
			t_list **fake_list);
int		in_range(t_list *stack_b, t_list *target, t_list **fake_list);
int		to_a_dist(t_list *stack_a, t_list *stack_b, t_list *to_move_b);

#endif
