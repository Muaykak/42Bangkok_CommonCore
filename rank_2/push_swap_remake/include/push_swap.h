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


struct	s_ps_stack;
struct	s_ps_node;

enum e_ps_stack_def
{
	A,
	B
};

typedef struct	s_ps_node
{
	int					number;
	struct s_ps_stack	*stack;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
	struct s_ps_node	*target_next;
	struct s_ps_node	*target_prev;
}				t_ps_node;

typedef struct	s_ps_stack
{
	enum e_ps_stack_def	stack;
	int					size;
	struct s_ps_node	*top;
	struct s_ps_node	*bot;
}				t_ps_stack;

/***************************************/
/*            CREATE STACK             */

char		***get_numsets(int argc, char **argv);
t_ps_stack	*create_stack_a(char ***numsets);

/*****************************************/
/*            NODE FUNCTIONS             */

void		ps_node_addback(t_ps_node **node_list, t_ps_node *node);
t_ps_node	*ps_node_new(t_ps_stack *stack, int num);
void		ps_node_delone(t_ps_node *node);
void		ps_node_clearall(t_ps_node **node_list);

/* ******** CHECK ARGUMENT ********* */

int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);
int		check_duplicate(t_ps_stack *stack_a);

/* *************** UTILITY ************** */

long	ft_atol(const char *nptr);
void	ft_free_split(char **save);
void	free_numsets(char ***numsets);

#endif
