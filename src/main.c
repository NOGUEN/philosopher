/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:55:08 by noguen            #+#    #+#             */
/*   Updated: 2022/02/25 13:47:05 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc < 5 || argc > 6)
		error_exit(0);
	init_all(&all, argc, argv);
	check_init(&all);
	thread_start(&all);
}
