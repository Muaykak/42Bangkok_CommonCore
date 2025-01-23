/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algor_redix.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:02:15 by srussame          #+#    #+#             */
/*   Updated: 2025/01/19 16:02:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGOR_REDIX_H
# define PUSH_SWAP_ALGOR_REDIX_H

# include "ft_push_swap.h"

int		number_digit(t_list *target, unsigned long digit);
t_list	*find_num_digit_high(t_list *stack, int find_num, unsigned long digit);
t_list	*find_num_digit_low(t_list *stack, int find_num, unsigned long digit);
void	redix_algor_sort(t_list	**stack_a, t_list **stack_b);
t_list	*find_min_number(t_list *stack);

#endif