/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:41:26 by srussame          #+#    #+#             */
/*   Updated: 2025/07/08 14:17:33 by muaykak          ###   ########.fr       */
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

/* STRUCTURE */
/*
	p_num = number of philosophers
	t_die = time to die
	t_eat = time to eat
	t_slp = time to sleep
	e_max = eat max of each philosophers

*/

typedef enum	e_philo_status
{
	UNACTIVE,
	ACTIVE,
	FINISH,
	DEAD,
	ERROR
}				t_philo_status;

typedef struct	s_thread_arg
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	int				thread_num;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				e_max;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	status_lock;
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
	pthread_mutex_t	*all_fork;
	pthread_t		*all_philo_thread;
	t_thread_arg	*all_thread_arg;
	struct timeval	start_time;
	pthread_mutex_t	print_lock;
}				t_philo_info;

/* ########################################  */

/* parser */

bool			philo_parser(t_philo_info *info, int argc, char **argv);

/* Initialization */

bool			philo_info_init(t_philo_info *info);
bool			philo_thread_init(t_philo_info *info);

/* Thread Management */
t_philo_status	get_philo_status(t_thread_arg *thread_arg);
bool			set_philo_status(t_thread_arg \
*arg, t_philo_status new_status);

/* utility */

int				ft_philo_atoi(char *strnum);
int				ft_strlen(char *str);
int				ft_isspace(int c);
void			ft_putstr_fd(char *str, int fd);
int				ft_isdigit(int c);
void			ft_putnbr_fd(int n, int fd);

void			free_mutex_array(pthread_mutex_t *mutex_array, int array_size);
void			free_philo_info(t_philo_info *info);

#endif