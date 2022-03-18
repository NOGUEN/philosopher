#include "../include/philosophers.h"

void	print_error(char *str)
{
	printf("\033[31m%s\n\033[0m", str);
}

void	print_log(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&(philo->all->printing));
	if (philo->all->stop_flag)
	{
		pthread_mutex_unlock(&(philo->all->printing));
		return ;
	}
	printf("\033[%dm", 31 + philo->id % 5);
	time = time_current() - philo->all->base_time;
	printf("%lld\t", time);
	printf("%d ", philo->id + 1);
	printf("%s", str);
	printf("\n\033[0m");
	pthread_mutex_unlock(&(philo->all->printing));
}
