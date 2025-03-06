/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils2_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:49:33 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 22:49:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_utils.h"

void	display_fake_stack(t_list *fake_list);
void	remove_lst_one(t_list **top, t_list *target);
void	del_fake_content(void *content);
int		show_fake_int(t_list *fake_list);

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

/* free the content in fake_list*/
void	del_fake_content(void *content)
{
	if (content != NULL)
		free(content);
}

/* show the integer of the value that fake list content it points to*/
int	show_fake_int(t_list *fake_list)
{
	if (fake_list)
		return (*((int *)((*((t_list **)(fake_list->content)))->content)));
	return (0);
}
