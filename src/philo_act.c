/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:48:17 by noguen            #+#    #+#             */
/*   Updated: 2022/02/24 15:03:04 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_act_eat(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(&(all->eating));
	print_log(all, "is eating", philo->id);
	philo->time = time_current();
	pthread_mutex_unlock(&(all->eating));
	philo->eat_cnt++;
	time_eating(all);
}

void	philo_act(t_all *all, t_philo *philo)
{
	pthread_mutex_lock(&(all->forks[philo->left_fork_idx]));
	print_log(all, "has taken a fork", philo->id);
	pthread_mutex_lock(&(all->forks[philo->right_fork_idx]));
	print_log(all, "has taken a fork", philo->id);
	philo_act_eat(all, philo);
	pthread_mutex_unlock(&(all->forks[philo->left_fork_idx]));
	pthread_mutex_unlock(&(all->forks[philo->right_fork_idx]));
}
