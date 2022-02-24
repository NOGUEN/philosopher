/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:55:08 by noguen            #+#    #+#             */
/*   Updated: 2022/02/24 13:57:24 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char *argv[])
{
	t_all	all;

	if (argc < 5 || argc > 6)
		error_exit(0);
	init_all(&all, argc, argv);
	check_init(&all);
	thread_start(&all);
	/*test print*/
	printf("philo number : %d\n", all.philo_number);
	printf("time to die : %d\n", all.time_to_die);
	printf("time to eat : %d\n", all.time_to_eat);
	printf("time to sleep : %d\n", all.time_to_sleep);
	printf("must eat number : %d\n", all.must_eat_number);
}
