/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:41:26 by srussame          #+#    #+#             */
/*   Updated: 2025/07/10 08:29:12 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>

/*   ARGUMENT LIMIT */

# ifndef MAX_PHILO_NUM
#  define MAX_PHILO_NUM 199
# endif

# ifndef MAX_TIME_MS
#  define MAX_TIME_MS 50000
# endif

# ifndef MAX_EAT
#  define MAX_EAT 20000
# endif


/* COLORS */
# ifndef RED
#  define RED "\033[0;31m"
# endif
# ifndef GREEN
#  define GREEN "\033[0;32m"
# endif
# ifndef YELLOW
#  define YELLOW "\033[0;33m"
# endif
# ifndef RESET
#  define RESET "\033[0;37m"
# endif

# ifndef PHILO_ERR_MSG_1
#  define PHILO_ERR_MSG_1 RED"ERROR: This program \
takes only "YELLOW"positive integer.\n"RESET"(each argument MUST \
contain only 1 number and should not contain \nany other things accept \
whitespaces (Eg. the"GREEN" \"      +21 \" is accepted"RESET")\n"
# endif

# ifndef PHILO_ERR_MSG_2
#  define PHILO_ERR_MSG_2 RED"Error: philo"\
":This program takes 4-5 arguments as follows\n\n"RESET \
YELLOW"1. number_of_philosophers \n"RESET \
YELLOW"2. time_to_die (in "RESET"milliseconds"YELLOW")\n"RESET \
YELLOW"3. time_to_eat (in "RESET"milliseconds"YELLOW")\n"RESET \
YELLOW"4. time_to_sleep (in "RESET"milliseconds"YELLOW")\n"RESET \
"(optional)"YELLOW"5. each philosophers eat max.\n"RESET
# endif

# ifndef PHILO_ERR_MSG_3
#  define PHILO_ERR_MSG_3 \
RED"Error: philo: initialization failed.\n"RESET
# endif

# ifndef PHILO_ERR_MSG_4
#  define PHILO_ERR_MSG_4 \
RED"Error: philo: The argument is out of range.\n"\
RESET"\tThe number should be MORE THAN "YELLOW"0"RESET \
" but not \nexceed MAX INT ("YELLOW"2147483647"RESET")\n"
# endif

# ifndef PHILO_ERR_MSG_5
#  define PHILO_ERR_MSG_5 \
RED"Error: philo: The argument EXCEED the project's defined limit: "RESET
# endif

# ifndef PHILO_ERR_MSG_6
#  define PHILO_ERR_MSG_6 \
RED"Error: philo: having some errors on pthread_mutex_lock() \
or pthread_mutex_unlock()\n"RESET
# endif

# ifndef PHILO_ERR_MSG_7
#  define PHILO_ERR_MSG_7 \
RED"Error: philo: gettimeofday(): Error occurred\n"RESET
# endif

# ifndef PHILO_ERR_MSG_8
#  define PHILO_ERR_MSG_8 \
RED"Error: philo: phtread_create(): Error occurred\n"RESET
# endif

# ifndef PHILO_ERR_MSG_9
#  define PHILO_ERR_MSG_9 \
RED"Error: philo: phtread_join(): Error occurred\n"RESET
# endif

# ifndef PHILO_LOG_TAKE_FORK
#  define PHILO_LOG_TAKE_FORK \
"has taken a fork"
# endif

# ifndef PHILO_LOG_EAT
#  define PHILO_LOG_EAT \
"is eating"
# endif

# ifndef PHILO_LOG_SLEEP
#  define PHILO_LOG_SLEEP \
"is sleeping"
# endif

# ifndef PHILO_LOG_THINK
#  define PHILO_LOG_THINK \
"is thinking"
# endif

# ifndef PHILO_LOG_DEAD
#  define PHILO_LOG_DEAD \
RED"died"RESET
# endif

# ifndef PHILO_LOG_FINISH
#  define PHILO_LOG_FINISH \
GREEN"is finished eating"RESET
# endif

/* STRUCTURE */
/*
	p_num = number of philosophers
	t_die = time to die
	t_eat = time to eat
	t_slp = time to sleep
	e_max = eat max of each philosophers

*/

typedef enum	e_log_status
{
	LOG_THINK,
	LOG_TAKE_FORK,
	LOG_EAT,
	LOG_SLEEP,
	LOG_FINISH,
	LOG_DEAD
}				t_log_status;

typedef enum	e_philo_status
{
	UNACTIVE,
	ACTIVE,
	FINISH,
	DEAD,
	ERROR
}				t_philo_status;

typedef struct s_philo_fork
{
	bool			is_using;
	pthread_mutex_t	lock;
}				t_philo_fork;

typedef struct	s_thread_arg
{
	t_philo_fork	*right;
	t_philo_fork	*left;
	int				thread_num;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				e_max;
	size_t			eat_count;
	pthread_mutex_t	*print_lock;
	bool			*print_status;
	t_philo_status	status;
	struct timeval	*start_time;
}				t_thread_arg;

typedef struct	s_philo_info
{
	int				p_num;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				e_max;
	t_philo_fork	*all_fork;
	pthread_t		*all_philo_thread;
	t_thread_arg	*all_thread_arg;
	struct timeval	start_time;
	bool			print_status;
	pthread_mutex_t	print_lock;
}				t_philo_info;

/* ########################################  */

/* MAIN PART */

void	*philo_routine(void *ptr);
void	philo_eat(t_thread_arg *arg, struct timeval *death_timer);
void	philo_sleep(t_thread_arg *arg, struct timeval *death_timer);
bool	create_all_philo(t_philo_info *info);
bool	join_all_philo(t_philo_info *info);
bool	philo_simulation(t_philo_info *info);

bool	is_philo_alive(struct timeval *death_timer);
void	set_deathtimer(struct timeval *death_timer, t_thread_arg *arg);

/* parser */

bool			philo_parser(t_philo_info *info, int argc, char **argv);

/* Initialization */

bool			philo_info_init(t_philo_info *info);
bool			philo_thread_init(t_philo_info *info);

/* Thread Management */
bool			get_print_status(t_thread_arg *arg);
bool			set_print_status(t_thread_arg *arg, bool new_status);

bool			print_philo_log(char *str, t_thread_arg *arg,
					t_log_status status);

/* utility */

int				ft_philo_atoi(char *strnum);
int				ft_strlen(char *str);
int				ft_isspace(int c);
void			ft_putstr_fd(char *str, int fd);
int				ft_isdigit(int c);
void			ft_putnbr_fd(int n, int fd);

void			free_philo_fork(t_philo_fork *fork_array, int array_size);
void			free_philo_info(t_philo_info *info);

void			ft_philo_wait(int time_ms, t_thread_arg *arg, struct timeval *death_timer);

#endif