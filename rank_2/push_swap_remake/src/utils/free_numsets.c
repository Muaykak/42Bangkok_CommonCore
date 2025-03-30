/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_numsets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:56:28 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 21:56:28 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_numsets(char ***numsets)
{
	int i;

	i = 0;
	if (numsets == NULL)
		return ;
	while (numsets[i] != NULL)
		ft_free_split(numsets[i++]);
	free(numsets);
	return ;
}
