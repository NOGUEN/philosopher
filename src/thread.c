#include "../include/philosophers.h"

void	thread_end(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->philo_number)
	{
		if (pthread_join(all->philos[i].t_id, NULL))
			error_exit(-7);
		if (pthread_join(all->philos[i].m_id, NULL))
			error_exit(-7);

	}
	i = -1;
	while (++i < all->philo_number)
	{
		pthread_mutex_destroy(&(all->forks[i]));
		pthread_mutex_destroy(&(all->philos[i].protect));
	}
	pthread_mutex_destroy(&(all->printing));
	free(all->philos);
	free(all->forks);
}

void	*thread_func(void *void_philo)
{
	t_philo	*philo;
	t_all	*all;

	philo = (t_philo *)void_philo;
	all = philo->all;
	if (philo->id % 2 == 1)
		usleep(1000 * all->time_to_eat);
	while (!all->death_flag)
	{
		philo_act_eat(philo);
		check_must_eat(philo->all);
		if (all->eat_flag)
			break ;
		if (all->death_flag)
			break ;
		philo_act_sleep(philo);
		if (philo->all->death_flag)
			break ;
		philo_act_think(philo);
		if (philo->all->death_flag)
			break ;
	}
	return (0);
}

void	*thread_check_func(void *void_philo)
{
	t_philo *philo;
	t_all	*all;

	philo = void_philo;
	all = philo->all;
	while (!all->death_flag)
	{
		pthread_mutex_lock(&(philo->protect));
		if (time_current() - philo->time >= all->time_to_die)
		{
			print_log(all, "died", philo->id);
			all->death_flag = 1;
			pthread_mutex_unlock(&(philo->protect));
			break ;
		}
		pthread_mutex_unlock(&(philo->protect));
		usleep(50);
	}
	return (0);
}

void	thread_start(t_all *all)
{
	int		i;

	i = -1;
	all->base_time = time_current();
	while (++i < all->philo_number)
	{
		all->philos[i].time = time_current();
		if (pthread_create(&(all->philos[i].t_id),
				NULL, thread_func, &all->philos[i]))
			error_exit(-6);
		if (pthread_create(&(all->philos[i].m_id),
				NULL, thread_check_func, &all->philos[i]));
			error_exit(-6);
	}
	thread_end(all);
}
