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

# ifndef PS_PRINT_OP
#  define PS_PRINT_OP 1
# endif

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
	int		sort_pos;
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
	int					all_num_size;
	struct s_ps_node	*min;
	struct s_ps_node	*max;
	struct s_ps_node	*top;
	struct s_ps_node	*bot;
}				t_ps_stack;

/**************************************************************/
/*                      PUSH_SWAP OPERATION                   */

void	op_sa(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_sb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_pb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_pa(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_ss(t_ps_stack *stack_a, t_ps_stack *stack_b);
void 	op_ra(t_ps_stack *stack_a, t_ps_stack *stack_b);
void 	op_rb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_rr(t_ps_stack *stack_a, t_ps_stack *stack_b);

void	op_sa_sub1(t_ps_stack *stack_a);
void	op_sb_sub1(t_ps_stack *stack_b);
void 	op_ra_sub1(t_ps_stack *stack_a);
void 	op_rb_sub1(t_ps_stack *stack_b);

/***************************************/
/*              PRE SORT               */

t_list	*create_pre_sort_stack(t_ps_stack *stack_a);
int		fill_pre_sort(t_list *pre_sort, t_ps_stack *stack_a);

/***************************************/
/*            CREATE STACK             */

char		***get_numsets(int argc, char **argv);
t_ps_stack	*create_stack_a(char ***numsets);
t_ps_stack	*create_stack_b(t_ps_stack *stack_a);
t_list		*pre_quicksort(t_list *pre_top);

/*****************************************/
/*            NODE FUNCTIONS             */

void		ps_node_addback(t_ps_node **node_list, t_ps_node *node);
void		ps_node_addfront(t_ps_node **node_list, t_ps_node *node);
t_ps_node	*ps_node_new(t_ps_stack *stack, int num);
void		ps_node_delone(t_ps_node *node);
void		ps_node_clearall(t_ps_node **node_list);

t_ps_node	*find_node(t_ps_node *node_list, int num_pos);

/* ******** CHECK ARGUMENT ********* */

int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);
int		check_duplicate(t_ps_stack *stack_a);

/* *************** UTILITY ************** */

long	ft_atol(const char *nptr);
void	ft_free_split(char **save);
void	free_numsets(char ***numsets);
void	free_pre_sort_content(void *p);
void	display_stacks(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	display_sorted_stack(t_ps_stack *stack);
int		show_ps_num(t_list *list);

#endif
