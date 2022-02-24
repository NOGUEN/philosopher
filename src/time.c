/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:16:10 by noguen            #+#    #+#             */
/*   Updated: 2022/02/24 19:23:11 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	time_current()
{
	struct timeval	t;
	long long		ms;

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (ms);
}

void	time_eating(t_all *all)
{
	long long	start_time;
	long long	current_time;

	start_time = time_current();
	while (!all->death_flag)
	{
		current_time = time_current();
		if (current_time - start_time >= all->time_to_eat)
			break ;
		usleep(10);
	}
}

void	time_sleeping(t_all *all)
{
	long long	start_time;
	long long	current_time;

	start_time = time_current();
	while (!all->death_flag)
	{
		current_time = time_current();
		if (current_time - start_time >= all->time_to_sleep)
			break ;
		usleep(10);
	}
}
