#include "../../include/philo.h"

t_philo_status	get_philo_status(t_thread_arg *thread_arg)
{
	t_philo_status	ret;

	if (!thread_arg)
		return (ft_putstr_fd(RED"Error: philo: check_dead_status(): \
The argument is null\n"RESET, 2), ERROR);
	if (pthread_mutex_lock(&thread_arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ERROR);
	ret = thread_arg->status;
	if (pthread_mutex_unlock(&thread_arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ERROR);
	return (ret);
}
