/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:33:59 by noguen            #+#    #+#             */
/*   Updated: 2022/02/20 14:15:29 by noguen           ###   ########.fr       */
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
