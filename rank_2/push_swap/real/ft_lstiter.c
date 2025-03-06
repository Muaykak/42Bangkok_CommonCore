/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:07:26 by muaykak           #+#    #+#             */
/*   Updated: 2024/11/05 08:23:34 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function is to apply the (void function that recieve void 
// pointer argument applied to every content in the list)
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
