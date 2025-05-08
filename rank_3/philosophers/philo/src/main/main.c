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

void display_timesec(struct timeval time)
{
	printf("%llu.%06ld Sec\n", (unsigned long long)time.tv_sec, (long)time.tv_usec);
}

void	display_allthread(t_philo_thread **threads)
{
	unsigned long long	i;

	if (threads == NULL)
		return ;
	i = 0;
	while (threads[i] != NULL)
	{
		printf("philo[%llu] rightfork: %p leftfork: %p\n", i, (threads[i])->fork_right, (threads[i])->fork_left);
		i++;
	}
}

void	*philo_routine(void *phi_thread)
{
	unsigned long long	i;
	t_philo_thread	*thread;

	if (phi_thread == NULL)
		return (NULL);
	thread = (t_philo_thread *)phi_thread;
	i = 0;
	printf("thread_num : %llu started\n", thread->thread_num);
	if (philo_lock(&(thread->philo_info->main_lock)) == 0)
		return (0);
	if (thread->philo_info->death_flag == TRUE)
	{
		philo_unlock(&(thread->philo_info->main_lock));
		return (0);
	}
	if (philo_unlock(&(thread->philo_info->main_lock)) == 0)
		return (0);
	while (i < 10000)
	{
//		if (i % 10000000 == 0)
//			printf("thread_num : %llu i: %llu\n", thread->thread_num, i);
		i++;
	}
	printf(GREEN_COLOR "thread_num : %llu SUCCESS!\n" RESET_COLOR, thread->thread_num);
	return (NULL);
}

int	run_all_philo(t_philo_thread **threads, void *philo_routine(void *))
{
	unsigned long long	i;

	if (threads == NULL)
		return (0);
	i = 0;
	if (philo_lock(&((*threads)->philo_info->main_lock)) == 0)
		return (0);
	while (threads[i] != NULL)
	{
		if (pthread_create(&((threads[i])->thread), NULL, \
		philo_routine, (void *)(threads[i])) != 0)
		{
			(*threads)->philo_info->death_flag = TRUE;
			ft_putstr_fd(RED_COLOR "\nERROR " RESET_COLOR \
			": pthread_create(); cannot put all philo threads to routines\n" \
			"thread_num :", 2);
			ft_putnbr_fd((long long)(threads[i])->thread_num, 2);
			ft_putstr_fd("\n\n", 2);
			if (philo_unlock(&((*threads)->philo_info->main_lock)) == 0)
				return (0);
			return (0);
		}
		(threads[i])->run_flag = TRUE;
		i++;
	}
	if (philo_unlock(&((*threads)->philo_info->main_lock)) == 0)
		return (0);
	return (1);
}

int	join_all_philo(t_philo_thread **threads)
{
	unsigned long long	i;

	if (threads == NULL)
		return (0);
	i = 0;
	while (threads[i] != NULL && (threads[i])->run_flag == TRUE)
	{
		if (pthread_join((threads[i])->thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo_info	philo_info;
	t_philo_thread	**threads;

	if (get_philo_info(&philo_info, argc, argv) == 0 \
	|| create_philo_fork(&philo_info) == 0 \
	|| create_philo_thread(&philo_info, &threads) == 0)
		return (1);
	printf("philo num: %llu\n" \
	"time_to_die : ", philo_info.philo_num);
	display_timesec(philo_info.time_to_die);
	printf("time_to_eat : ");
	display_timesec(philo_info.time_to_eat);
	printf("time_to_sleep : ");
	display_timesec(philo_info.time_to_sleep);
	printf("eat_count_max: %llu\n", philo_info.eat_count_max);
	display_allthread(threads);
	run_all_philo(threads, &philo_routine);
	join_all_philo(threads);
	if (philo_info.death_flag == TRUE)
		printf(RED_COLOR "It's dead!\n" RESET_COLOR);
	printf("will test the speed of print_timestamp\n");
	t_perform_time	time_take;
	gettimeofday(&(time_take.start), NULL);
	exact_delay_usec(10000);
	time_taken_cal(&time_take);
	printf("\n\n time taken: %ld.%06ld Seconds\n", time_take.cal.tv_sec, time_take.cal.tv_usec);
	free_philo_array((void **)threads);
	free_philo_fork(philo_info.fork);
    return (0);
}
