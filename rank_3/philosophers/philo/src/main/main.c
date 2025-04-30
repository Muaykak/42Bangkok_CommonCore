/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:32:53 by srussame          #+#    #+#             */
/*   Updated: 2025/04/23 10:56:07 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*hello(void *philo)
{
	t_philo		*phi;
	size_t		i;

	phi = (t_philo *)(philo);
	printf("thread ID: %ld\n", (long)(phi->thread));
	printf("start looping\n");
	i = 0;
	while (i < 10000000)
	{
		i++;
	}
	printf("thread %ld finished looping\n", (long)(phi->thread));
	return (NULL);
}

void	philo_init(t_philo *philo, size_t thread_num)
{
	if (philo == NULL)
		return ;
	philo->thread_num = thread_num;
	return ;
}

int	time_taken_cal(t_perform_time *time)
{
	struct timeval	end;

	if (time == NULL)
		return (0);
	memset(&end, 0, sizeof(end));
	if (gettimeofday(&(end), NULL) != 0)
		return (0);
	time->cal.tv_sec = end.tv_sec - time->start.tv_sec;
	if (time->start.tv_usec > end.tv_usec)
	{
		time->cal.tv_usec = end.tv_usec + (1000000 - time->start.tv_usec);
		time->cal.tv_sec--;
	}
	else
		time->cal.tv_usec = end.tv_usec - time->start.tv_usec;
	return (1);
}

// display time in second and microseconds
void	display_timesec(struct timeval time)
{
	int	temp;
	int	i;

	printf("%zu.", time.tv_sec);
	i = 0;
	temp = time.tv_usec;
	while (temp / 10 > 0)
	{
		temp /= 10;
		i++;
	}
	while (i++ < 5)
		printf("0");
	printf("%d\n", time.tv_usec);
}

int	main(int argc, char **argv)
{
	t_philo_info	philo_info;
	t_philo_thread	**threads;

	if (get_philo_info(&philo_info, argc, argv) == 0 \
	|| create_philo_fork(&philo_info) == 0 \
	|| create_philo_thread(&philo_info, &threads) == 0)
		return (1);
	printf("philo num: %zu\n" \
	"time_to_die : ", philo_info.philo_num);
	display_timesec(philo_info.time_to_die);
	printf("time_to_eat : ");
	display_timesec(philo_info.time_to_eat);
	printf("time_to_sleep : ");
	display_timesec(philo_info.time_to_sleep);
	printf("eat_count_max: %zu\n", philo_info.eat_count_max);
    return (0);
}
