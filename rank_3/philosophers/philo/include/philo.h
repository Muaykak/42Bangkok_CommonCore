/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:41:26 by srussame          #+#    #+#             */
/*   Updated: 2025/07/05 23:32:27 by srussame         ###   ########.fr       */
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
#  define PHILO_ERR_MSG_1 RED"\nERROR: This program \
takes only "YELLOW"positive integer.\n"RESET"(each argument can \
contain only 1 number and should not contain \nany other things accept \
whitespaces (Eg. the"GREEN" \"      +21 \" is accepted"RESET")\n\n"
# endif

# ifndef PHILO_ERR_MSG_2
#  define PHILO_ERR_MSG_2 RED"\nError: philo"\
":This program takes 5-6 arguments as follows\n\n"RESET \
YELLOW"1. number_of_philosophers \n"RESET \
YELLOW"2. time_to_die (in "RESET"milliseconds"YELLOW")\n"RESET \
YELLOW"3. time_to_eat (in "RESET"milliseconds"YELLOW")\n"RESET \
YELLOW"4. time_to_sleep (in "RESET"milliseconds"YELLOW")\n"RESET \
"(optional)"YELLOW"5. each philosophers eat max.\n\n"RESET
# endif

# ifndef PHILO_ERR_MSG_3
#  define PHILO_ERR_MSG_3 \
RED"\nError: philo: invalid argument.\n"\
RESET"\tThe argument is empty, or the format is invalid\n"
# endif

# ifndef PHILO_ERR_MSG_4
#  define PHILO_ERR_MSG_4 \
RED"\nError: philo: The argument is out of range.\n"\
RESET"\tThe number should be more than "YELLOW"1"RESET \
" but not \nexceed MAX INT ("YELLOW"2147483647"RESET")\n\n"
# endif

# ifndef PHILO_ERR_MSG_5
#  define PHILO_ERR_MSG_5 \
RED"\nError: philo: The argument EXCEED the project's defined limit: "RESET
# endif

/* STRUCTURE */
/*
	p_num = number of philosophers
	t_die = time to die
	t_eat = time to eat
	t_slp = time to sleep
	e_max = eat max of each philosophers

*/

typedef struct	s_philo_info
{
	int	p_num;
	int	t_die;
	int	t_eat;
	int	t_slp;
	int	e_max;
}				t_philo_info;

/* ########################################  */

/* parser */

bool	philo_parser(t_philo_info *info, int argc, char **argv);

/* utility */

int		ft_philo_atoi(char *strnum);
int		ft_strlen(char *str);
int		ft_isspace(int c);
void	ft_putstr_fd(char *str, int fd);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);

#endif