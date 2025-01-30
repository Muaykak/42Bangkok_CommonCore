/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:22:16 by srussame          #+#    #+#             */
/*   Updated: 2025/01/25 09:22:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_QUICKSORT_H
# define PUSH_SWAP_QUICKSORT_H

# include "ft_push_swap.h"

void	quicksort_main(t_list *top, t_list *bottom,
		 t_list **stack_a, t_list **stack_b);

# endif