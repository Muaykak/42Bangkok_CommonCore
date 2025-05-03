/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:29:13 by srussame          #+#    #+#             */
/*   Updated: 2025/04/23 09:02:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdlib.h>

/* ******** ANSI COLOR CODES ******** */
# define RESET_COLOR "\033[0m"
# define RED_COLOR "\033[31m"
# define GREEN_COLOR "\033[32m"
# define YELLOW_COLOR "\033[33m"
/**/

# ifndef PTHREAD_MAX
#  define PTHREAD_MAX 1000000
# endif

# ifndef SSIZE_MAX
#  define SSIZE_MAX 9223372036854775807
# endif

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct	s_philo_fork
{
	int				init_flag;
	pthread_mutex_t	fork;
}				t_philo_fork;

typedef struct	s_philo_info
{
	unsigned long long	philo_num;
	struct timeval		time_to_die;
	struct timeval		time_to_eat;
	struct timeval		time_to_sleep;
	int					optional_flag;
	unsigned long long	eat_count_max;
	t_philo_fork		**fork;
	t_bool				death_flag;
}				t_philo_info;

typedef struct	s_philo_thread
{
	unsigned long long	thread_num;
	pthread_t			thread;
	t_bool				run_flag;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	t_philo_info		*philo_info;
	unsigned long long	eat_max;
	t_bool				success_flag;
}				t_philo_thread;

typedef struct	s_philo_args
{

	unsigned long long	philo_num;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					optional_flag;
	unsigned long long	eat_count_max;
}	t_philo_args;

typedef struct s_perform_time
{
	struct timeval	start;
	struct timeval	cal;
}				t_perform_time;

/* ** MAIN PART ** */
int	create_philo_fork(t_philo_info *info);
int	create_philo_thread(t_philo_info *info, t_philo_thread ***thread_array);

/* PARSER */
int	get_philo_info(t_philo_info *philo_info, int argc, char **argv);
int	get_philo_args(t_philo_args *philo_args, int argc, char **argv);
int	ft_check_digits(char *str);
int	ft_check_strnum(char *str);


//Error message
void	parser_message1(void);

/* ****     UTILITY    **** */
int	ft_isspace(char c);
int	exact_delay_usec(int usec);

int	time_taken_cal(t_perform_time *time);

unsigned long long	ft_atollu(char *str);
unsigned long long	ft_strlen(const char *str);
ssize_t	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(long long n, int fd);

void	free_philo_array(void **thread_array);
void	free_philo_fork(t_philo_fork **fork);

#endif
