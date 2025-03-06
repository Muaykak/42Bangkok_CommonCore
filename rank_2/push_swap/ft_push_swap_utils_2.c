/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:11 by srussame          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:12 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_utils.h"

t_list *chunk_fakelist(t_list **fake_list, int chunk_size);
void	remove_lst_one(t_list **top, t_list *target);
void	del_fake_content(void *content);
t_list	*fake_quicksort(t_list *fake_head);
void	fake_quicksort_sub(t_list *fake_head, t_list *fake_tail);
t_list	*fake_pivot_partition(t_list *fake_head, t_list *fake_tail);
void	display_fake_stack(t_list *fake_list);
int		show_fake_int(t_list *fake_list);
t_list	*copy_to_fake(t_list *stack_a);

t_list	*copy_to_fake(t_list *stack_a)
{
	t_list **real_point;
	t_list *fake_stack;

	real_point = 0;
	fake_stack = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		real_point = (t_list **)malloc(sizeof(t_list *));
		if (real_point == 0)
			return (0);
		real_point[0] = stack_a;
		ft_lstadd_back(&fake_stack, ft_lstnew(&real_point[0]));
		real_point = NULL;
		stack_a = stack_a->next;
	}
	return (fake_stack);
	
}

/* show the integer of the value that fake list content it points to*/
int	show_fake_int(t_list *fake_list)
{
	if (fake_list)
		return (*((int *)((*((t_list **)(fake_list->content)))->content)));
	return (0);
}

/* This function is to display the fake stack*/
void	display_fake_stack(t_list *fake_list)
{
	if (!fake_list)
		return ;
	ft_printf("fake: {");
	while (fake_list)
	{
		ft_printf("%d", show_fake_int(fake_list));
		if (fake_list->next != 0)
			ft_printf(", ");
		fake_list = fake_list->next;
	}
	ft_printf("}\n");
}

t_list	*fake_pivot_partition(t_list *fake_head, t_list *fake_tail)
{
	t_list	*pivot;
	t_list	*pre;
	t_list	*curr;
	t_list	*temp;

	pivot = fake_head;
	pre = fake_head;
	curr = fake_head;
	while (curr != fake_tail->next)
	{
		temp = 0;
		if (show_fake_int(curr) < show_fake_int(pivot))
		{
			temp = (t_list *)curr->content;
			curr->content = pre->next->content;
			pre->next->content = temp;
			pre = pre->next;
		}
		curr = curr->next;
	}
	temp = (t_list *)pivot->content;
	pivot->content = (t_list *)pre->content;
	pre->content = (t_list *)temp;
	return (pre);
}

/* use quicksort algorithm to sort the fake_list*/
void	fake_quicksort_sub(t_list *fake_head, t_list *fake_tail)
{
	t_list	*pivot;

	if (!fake_head|| !fake_tail || fake_head == fake_tail)
		return ;
	pivot = fake_pivot_partition(fake_head, fake_tail);
	fake_quicksort_sub(fake_head, pivot);
	fake_quicksort_sub(pivot->next, fake_tail);
}

/* main function of fake quicksort */
t_list	*fake_quicksort(t_list *fake_head)
{
	t_list	*fake_tail;

	fake_tail = ft_lstlast(fake_head);
	fake_quicksort_sub(fake_head, fake_tail);
	return (fake_head);
}

/* free the content in fake_list*/
void	del_fake_content(void *content)
{
	if (content != NULL)
		free(content);
}

/* remove the target content inside the list*/
void	remove_lst_one(t_list **top, t_list *target)
{
	t_list	*head;

	if (!top || !(*top) || !target)
		return ;
	if (target == *top)
	{
		*top = (*top)->next;
		ft_lstdelone(target, &del_fake_content);
		return ;
	}
	head = *top;
	while (*top != 0 && (*top)->next != target)
	{
		*top = (*top)->next;
	}
	if ((*top) == 0)
	{
		*top = head;
		return ;
	}
	(*top)->next = target->next;
	ft_lstdelone(target, &del_fake_content);
	*top = head;
}

/* clear all the sorted fake_list and leave only the last number of each chunk
	(highest number on each chunk) the chunk separated by the 
	CHUNK_SIZE which is defined is the header file */
t_list *chunk_fakelist(t_list **fake_list, int chunk_size)
{
	int		chunk_value;
	int		i;
	t_list	*temp;
	t_list	*temp_2;

	if (!fake_list || !(*fake_list))
		return (0);
	if (chunk_size >= ft_lstsize(*fake_list))
		return (*fake_list);
	chunk_value = ft_lstsize(*fake_list) / chunk_size;
	temp = *fake_list;
	while (temp != 0)
	{
		i = 1;
		while (i < chunk_value && temp->next != 0)
		{
			temp_2 = temp->next;
			remove_lst_one(fake_list, temp);
			temp = temp_2;
			i++;
		}
		temp = temp->next;
	}
	return (*fake_list);
}
