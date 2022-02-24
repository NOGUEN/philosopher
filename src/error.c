/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:55:07 by noguen            #+#    #+#             */
/*   Updated: 2022/02/21 19:15:32 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	error_exit(int code)
{
	if (code <= 0 && code >= -6)
		error_exit1(code);
	exit(0);
}

void	error_exit1(int code)
{
	if (code == 0)
		print_error("Invalid number of parameters.");
	else if (code == -1)
		print_error("Parameter is not number.");
	else if (code == -2)
		print_error("Parameter is negative number.");
	else if (code == -3)
		print_error("Mutex init error.");
	else if (code == -4)
		print_error("Malloc error.");
	else if (code == -5)
		print_error("Wrong philosopher number.");
	else if (code == -6)
		print_error("pthread_create error.");
}
