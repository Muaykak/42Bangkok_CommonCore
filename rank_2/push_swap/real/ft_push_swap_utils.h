/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:04:45 by srussame          #+#    #+#             */
/*   Updated: 2025/01/14 12:04:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_UTILS_H
# define FT_PUSH_SWAP_UTILS_H

# include "ft_push_swap.h"

long	ft_atol(const char *nptr);
int		ft_isspace(char c);
void	free_number(void *number);
void	ft_free_split(char **save);
void	stack_display(t_list *stack_a, t_list *stack_b);
int		ft_abs(int number);
int		high_num(t_list *stack);
int		low_num(t_list *stack);
int		show_int(t_list *stack);

t_list	*chunk_fakelist(t_list **fake_list, int chunk_size);
void	remove_lst_one(t_list **top, t_list *target);
void	del_fake_content(void *content);
t_list	*fake_quicksort(t_list *fake_head);
void	fake_quicksort_sub(t_list *fake_head, t_list *fake_tail);
t_list	*fake_pivot_partition(t_list *fake_head, t_list *fake_tail);
void	display_fake_stack(t_list *fake_list);
int		show_fake_int(t_list *fake_list);
t_list	*copy_to_fake(t_list *stack_a);

t_list	*find_min_number(t_list *stack);
t_list	*find_max_number(t_list *stack);

#endif
