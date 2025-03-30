/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:25:57 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 15:25:58 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>


enum e_ps_stack_def
{
	STACK_A,
	STACK_B
};

typedef struct	s_ps_node
{
	enum e_ps_stack_def	stack;
	int					number;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
	struct s_ps_node	*target_next;
	struct s_ps_node	*target_prev;
}				t_ps_node;

typedef struct	s_ps_stack
{
	enum e_ps_stack_def	stack;
	struct s_ps_list	*top;
	struct s_ps_lsit	*bot;
}				t_ps_stack;

/* ********* CREATE STACK ********** */

char	***get_numsets(int argc, char **argv);

/* ******** CHECK ARGUMENT ********* */

int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);

/* *************** UTILITY ************** */

long	ft_atol(const char *nptr);
void	ft_free_split(char **save);
void	free_numsets(char ***numsets);

#endif
