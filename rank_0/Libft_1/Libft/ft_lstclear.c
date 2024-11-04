/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:20:14 by srussame          #+#    #+#             */
/*   Updated: 2024/11/03 14:09:09 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_lstclear(t_list **lst, void *(del)(void *))
//{
//	t_list	*temp;
//	
//	if (lst == 0 || *lst == 0)
//		return ;
//	while (
//}

#include <stdio.h>

void	delete_malloc(void *ptr)
{
	if (ptr != 0 )
		free(ptr);
	ptr = 0;
	free(ptr);
}

int main(int ac, char **argv)
{
	char	**str_set;
	int		i;
	t_list	*word_list;
	t_list	*start_list;


	if (ac < 2)
		return (0);
	str_set = (char **)malloc(ac * (sizeof(char *)));
	if (!str_set)
		return (0);
	str_set[ac] = 0;
	i = 0;
	while (i < ac - 1)
	{
		str_set[i] = ft_strdup(argv[i + 1]);
		if (i == 0)
			word_list = ft_lstnew(str_set[i]);
		else
			ft_lstadd_back(&word_list, (void *)str_set[i]);
		i++;
	}
	i = 0;
	start_list = word_list;
	while (start_list != 0)
	{
		printf("str_set[%d] = \"%s\"\n", i, (char *)start_list->content);
		start_list = start_list->next;
	}
	return (0);
}
