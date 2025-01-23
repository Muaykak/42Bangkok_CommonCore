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

void	easy_rotate(char c, t_list **stack, t_list *target);
int 	(*decide_rotate(t_list *stack, t_list *target))(t_list **);

#endif
