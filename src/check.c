/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:33:59 by noguen            #+#    #+#             */
/*   Updated: 2022/02/24 14:41:34 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_number(char *str)
{
	int	tmp;

	tmp = 0;
	if (utils_isnum(str))
		tmp = utils_atoi(str);
	else
		error_exit(-1);
	if (tmp <= 0)
		error_exit(-2);
	return (tmp);
}

void	check_init(t_all *all)
{
	if (all->philo_number < 2 || all->philo_number > 200)
		error_exit(-5);
}

void	check_must_eat(t_all *all, t_philo *philo)
{
	int	i;

	i = -1;
	if (all->must_eat_number != 0)
	{
		while (++i < all->philo_number)
		{
			if (philo[i].eat_cnt >= all->must_eat_number)
				i++;
			else
				break ;
		}
		if (i == all->philo_number)
			all->eat_flag = 1;
	}
}

void	check_death(t_all *all, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < all->philo_number && !all->death_flag)
		{
			pthread_mutex_lock(&(all->eating));
			if (time_current() - philo[i].time > all->time_to_die)
			{
				print_log(all, "died", i);
				all->death_flag = 1;
			}
			pthread_mutex_unlock(&(all->eating));
		}
		if (all->death_flag)
			break ;
		check_must_eat(all, all->philos);
	}
}
