/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:42:16 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 16:18:26 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		num;
	char	c;

	if (nptr == 0)
		return (0);
	i = 0;
	num = 0;
	c = 0;
	while ((*(nptr + i) < '0' || *(nptr + i) > '9')
		&& ft_isspace(*(nptr + i)) != 0 && *(nptr + i) != '\0')
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		c = *(nptr + i);
		i++;
	}
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		num = (num * 10) + *(nptr + i) - 48;
		i++;
	}
	if (c == '-')
		num = num * -1;
	return (num);
}

// to check if the given character is whitespace characters
static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
