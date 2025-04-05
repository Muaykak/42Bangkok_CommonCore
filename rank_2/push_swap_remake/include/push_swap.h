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

# ifndef CHUNK_SEP
#  define CHUNK_SEP 4
# endif

struct	s_ps_stack;
struct	s_ps_node;

typedef enum e_ps_bool
{
	FALSE,
	TRUE
}			t_ps_bool;

enum e_ps_stack_def
{
	A,
	B
};

typedef struct	s_ps_node
{
	int					number;
	int					sort_pos;
	int					stack_pos;
	int					optional;
	t_ps_bool			unorder;
	t_ps_bool			swap_able;
	t_ps_bool			swap_top;
	struct s_ps_stack	*stack;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
	struct s_ps_node	*target_next;
	struct s_ps_node	*target_prev;
	struct s_ps_node	*st_next;
	struct s_ps_node	*st_prev;
}				t_ps_node;

typedef struct	s_ps_stack
{
	enum e_ps_stack_def	stack;
	int					size;
	int					all_num_size;
	t_ps_bool			sorted;
	struct s_ps_node	*stack_min;
	struct s_ps_node	*stack_max;
	struct s_ps_node	*min;
	struct s_ps_node	*max;
	struct s_ps_node	*top;
	struct s_ps_node	*bot;
	struct s_ps_stack	*link;
}				t_ps_stack;

/**************************************************************/
/*                      ALGORITHM FUNCTIONS                   */

// Fisrt 1st algorithm

void		first_algor(t_ps_stack *stack_a);
t_ps_node	*find_closest_to_swap(t_ps_stack *stack);
t_ps_node	*find_closest_to_push_b(t_ps_stack *stack);
t_ps_node	*find_closest_unsorted(t_ps_stack *stack);
t_ps_node	*find_target_in_a(t_ps_node *target_b);
t_ps_node	*find_closest_to_push_a(t_ps_stack *stack_b);
t_ps_node	*find_to_top_b(t_ps_node *target_a);
int			range_to_push_b(t_ps_stack *stack_a);
int			range_to_push_a(t_ps_stack *stack_b);

/**************************************************************/
/*                      PUSH_SWAP OPERATION                   */

void	easy_rotate(t_ps_node *target);
void	easy_both_rotate(t_ps_node *target_a, t_ps_node *target_b);

void	op_sa(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_sb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_pb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_pa(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_ss(t_ps_stack *stack_a, t_ps_stack *stack_b);
void 	op_ra(t_ps_stack *stack_a, t_ps_stack *stack_b);
void 	op_rb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_rr(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_rra(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_rrb(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	op_rrr(t_ps_stack *stack_a, t_ps_stack *stack_b);

void	(*rotate_decider(t_ps_node *target))(t_ps_stack *, t_ps_stack *);
void	(*both_rotate_decider(t_ps_node *target_a, t_ps_node *target_b))(
			t_ps_stack *, t_ps_stack *);

int		dist_cal(t_ps_node *start, t_ps_node *end);
int		dist_cal_rotate(t_ps_node *start, t_ps_node *end);
int		dist_cal_reverse(t_ps_node *start, t_ps_node *end);

void	op_sa_sub1(t_ps_stack *stack_a);
void	op_sb_sub1(t_ps_stack *stack_b);
void 	op_ra_sub1(t_ps_stack *stack_a);
void 	op_rb_sub1(t_ps_stack *stack_b);
void	op_rra_sub1(t_ps_stack *stack_a);
void	op_rrb_sub1(t_ps_stack *stack_b);

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
void		assign_stack_unsorted(t_ps_stack *stack);
void		assign_stack_pos(t_ps_stack *stack);
void		assign_node_unsorted(t_ps_node *node);

/*****************************************/
/*            NODE FUNCTIONS             */

void		ps_node_addback(t_ps_node **node_list, t_ps_node *node);
void		ps_node_addfront(t_ps_node **node_list, t_ps_node *node);
t_ps_node	*ps_node_new(t_ps_stack *stack, int num);
void		ps_node_delone(t_ps_node *node);
void		ps_node_clearall(t_ps_node **node_list);

t_ps_node	*find_node_sort_pos(t_ps_node *node_list, int sort_pos);
t_ps_node	*find_lower_node(t_ps_node *target);
t_ps_node	*find_higher_node(t_ps_node *target);

/* ********         CHECK FUNCTIONS         ********* */
/*                                                    */

int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);
int		check_duplicate(t_ps_stack *stack_a);

int		check_stack_asc_sorted(t_ps_stack *stack);
int		check_stack_desc_sorted(t_ps_stack *stack);

int		check_swapable(t_ps_node *target);
int		check_unsorted(t_ps_node *target);

/* *************** UTILITY ************** */

long	ft_atol(const char *nptr);
void	ft_free_split(char **save);
void	free_numsets(char ***numsets);
void	free_pre_sort_content(void *p);
void	display_stacks(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	display_sorted_stack(t_ps_stack *stack);
int		show_ps_num(t_list *list);

#endif
