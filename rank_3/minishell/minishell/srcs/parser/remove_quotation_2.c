/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:33 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:34 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Count until found quote like ' or "
*/
size_t	count_until_quote(char *word)
{
	size_t	i;

	if (!word)
		return (0);
	i = 0;
	while (word[i] != '\0' && word[i] != '\'' && word[i] != '\"')
		i++;
	return (i);
}
