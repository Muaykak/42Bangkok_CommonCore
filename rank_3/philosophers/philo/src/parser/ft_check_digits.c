/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:24:13 by srussame          #+#    #+#             */
/*   Updated: 2025/04/28 17:24:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_check_digits(char *str);
static int	get_ssize_t_digit(void);
static void	error_message1(void);

/* After passing the ft_check_strnum function
	need to check that if the number in string format is not exceed the limit
	so my limit is the SSIZE_T_MAX number of digits
		- any number in string format that exceeds SSIZE_T_MAX digits is not
		accepted
*/
int	ft_check_digits(char *str)
{
	int	i;
	int	digits;

	if (str == NULL)
		return (0);
	i = 0;
	digits = 0;
	while (str[i] != '\0' && (str[i] < '1' || str[i] > '9'))
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		i++;
		digits++;
	}
	if (digits == 0)
		digits = 1;
	if (digits > get_ssize_t_digit())
		return (error_message1(), 0);
	return (1);
}

static void	error_message1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": the number in the argument exceeds the max this program allowed\n"\
	"\tshould not exceeds the LLONG_MAX (it's " YELLOW_COLOR, 2);
	ft_putnbr_fd((long long)LLONG_MAX, 2);
	ft_putstr_fd(RESET_COLOR " )\n\n", 2);
}

static int	get_ssize_t_digit(void)
{
	int			digits;
	long long	num;

	digits = 1;
	num = LLONG_MAX;
	while (num / 10 > 0)
	{
		digits++;
		num = num / 10;
	}
	return (digits);
}
