/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:42:16 by srussame          #+#    #+#             */
/*   Updated: 2024/08/26 17:42:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		num;
	char	*ptr;

	i = 0;
	num = 0;
	ptr = 0;
	while ((*(nptr + i) < '0' || *(nptr + i) > '9') \
	&& ft_isspace(*(nptr + i)) != 0 && *(nptr + i) != '\0')
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		ptr = (char *)(nptr + i);
		i++;
	}
	else
		return (0);
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		num = (num * 10) + *(nptr + i) - 48;
		i++;
	}
	if (*ptr == '-')
		num = num * -1;
	return (num);
}

// to check if the given character is whitespace characters
int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
