/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:16:10 by noguen            #+#    #+#             */
/*   Updated: 2022/02/21 15:21:31 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long long	time_get()
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

	start_time = time_get();
	while (!all->death_flag)
	{
		current_time = time_get();
		if (current_time - start_time >= all->time_to_eat)
			break ;
	}
}

void	time_sleeping(t_all *all)
{
	long long	start_time;
	long long	current_time;

	start_time = time_get();
	while (!all->death_flag)
	{
		current_time = time_get();
		if (current_time - start_time >= all->time_to_sleep)
			break ;
	}
}
