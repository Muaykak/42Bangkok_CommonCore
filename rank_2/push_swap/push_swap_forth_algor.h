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

//typedef struct s_fakelist
//{
//	t_list 				*list;
//	int					part;
//	struct s_fakelist	*next;
//}				t_fakelist;

void	cost_algor(t_list **stack_a, t_list **stack_b);

#endif
