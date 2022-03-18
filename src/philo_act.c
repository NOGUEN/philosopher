#include "../include/philosophers.h"

void	philo_act_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->forks[philo->right_fork_idx]);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->all->forks[philo->left_fork_idx]);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->protect);
	print_log(philo, "is eating");
	philo->time = time_current();
	pthread_mutex_unlock(&philo->protect);
	while (time_current() - philo->time <= philo->all->time_to_eat)
	{
		usleep(1000);
	}
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->all->forks[philo->right_fork_idx]);
	print_log(philo, "put down the fork");
	pthread_mutex_unlock(&philo->all->forks[philo->left_fork_idx]);
	print_log(philo, "put down the fork");
}

void	philo_act_sleep(t_philo *philo)
{
	long long	start_time;

	start_time = time_current();
	print_log(philo, "is sleeping");
	while (time_current() - start_time <= philo->all->time_to_sleep &&
		!philo->all->stop_flag)
		usleep(1000);
}

void	philo_act_think(t_philo *philo)
{
	print_log(philo, "is thinking");
}
