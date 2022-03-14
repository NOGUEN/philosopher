#include "../include/philosophers.h"

void	init_mutex(t_all *all)
{
	int	idx;

	all->forks = malloc(sizeof(pthread_mutex_t) * all->philo_number);
	if (!(all->forks))
		error_exit(-4);
	idx = -1;
	while (++idx < all->philo_number)
		if (pthread_mutex_init(&(all->forks[idx]), NULL))
			error_exit(-3);
	if (pthread_mutex_init(&(all->printing), NULL))
		error_exit(-3);
	idx = -1;
	while (++idx < all->philo_number)
		if (pthread_mutex_init(&(all->philos[idx].protect), NULL))
			error_exit(-4);
}

void	init_philosophers(t_all *all)
{
	int	idx;

	idx = -1;
	all->philos = malloc(sizeof(t_philo) * all->philo_number);
	if (!(all->philos))
		error_exit(-4);
	while (++idx < all->philo_number)
	{
		all->philos[idx].id = idx;
		all->philos[idx].left_fork_idx = idx;
		all->philos[idx].right_fork_idx = (idx + 1) % all->philo_number;
		all->philos[idx].time = 0;
		all->philos[idx].eat_cnt = 0;
		all->philos[idx].all = all;
	}
}

void	init_all(t_all *all, int argc, char *argv[])
{
	all->philo_number = check_number(argv[1]);
	all->time_to_die = check_number(argv[2]);
	all->time_to_eat = check_number(argv[3]);
	all->time_to_sleep = check_number(argv[4]);
	all->death_flag = 0;
	all->eat_flag = 0;
	all->base_time = 0;
	if (argc == 6)
		all->must_eat_number = check_number(argv[5]);
	else
		all->must_eat_number = 0;
	init_philosophers(all);
	init_mutex(all);
}
