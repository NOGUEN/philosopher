/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:58:56 by noguen            #+#    #+#             */
/*   Updated: 2022/02/25 13:45:15 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	thread_end(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->philo_number)
		pthread_join(all->philos[i].t_id, NULL);
	i = -1;
	while (++i < all->philo_number)
		pthread_mutex_destroy(&(all->forks[i]));
	pthread_mutex_destroy(&(all->printing));
	pthread_mutex_destroy(&(all->eating));
	free(all->philos);
	free(all->forks);
}

void	*thread_func(void *void_philo)
{
	t_all	*tmp_all;
	t_philo	*tmp_philo;

	tmp_philo = (t_philo *)void_philo;
	tmp_all = tmp_philo->all;
	if (tmp_philo->id % 2 == 1)
		usleep(10000);
	while (!tmp_all->death_flag)
	{
		philo_act(tmp_all, tmp_philo);
		if (tmp_all->eat_flag)
			break ;
		print_log(tmp_all, "is sleeping", tmp_philo->id);
		time_sleeping(tmp_all);
		print_log(tmp_all, "is thinking", tmp_philo->id);
	}
	return (0);
}

void	thread_start(t_all *all)
{
	int		i;
	void	*void_philo;

	i = -1;
	all->base_time = time_current();
	while (++i < all->philo_number)
	{
		all->philos[i].time = time_current();
		void_philo = (void *)&(all->philos[i]);
		if (pthread_create(&(all->philos[i].t_id),
				NULL, thread_func, void_philo))
			error_exit(-6);
	}
	check_death(all, all->philos);
	thread_end(all);
}
