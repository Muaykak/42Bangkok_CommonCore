/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:41:26 by srussame          #+#    #+#             */
/*   Updated: 2025/07/05 18:23:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

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
whitespaces (Eg. the"GREEN" \"      21 \" is accepted"RESET")\n\n"
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

/* STRUCTURE */

typedef struct	s_philo_info
{
	int				philo_amount;
	struct timeval	time_die;
	struct timeval	time_eat;
	struct timeval	time_sleep;
	int				eat_max;
}				t_philo_info;

/* ########################################  */

/* parser */

bool	philo_parser(t_philo_info **info, int argc, char **argv);

/* utility */

int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);

#endif