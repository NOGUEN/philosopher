/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:55:07 by noguen            #+#    #+#             */
/*   Updated: 2022/02/21 14:42:53 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	error_exit(int code)
{
	if (code == 0)
		write(1, "\033[31mInvalid number of parameters.\n\033[0m",
			utils_strlen("\033[31mInvalid number of parameters.\n\033[0m"));
	else if (code == -1)
		write(1, "\033[31mParameter is not number.\n\033[0m",
			utils_strlen("\033[31mParameter is not number.\n\033[0m"));
	else if (code == -2)
		write(1, "\033[31mParameter is negative number.\n\033[0m",
			utils_strlen("\033[31mParameter is negative number.\n\033[0m"));
	else if (code == -3)
		write(1, "\033[31mMutex init error.\n\033[0m",
			utils_strlen("\033[31mMutex init error.\n\033[0m"));
	else if (code == -4)
		write(1, "\033[31mMalloc error.\n\033[0m",
			utils_strlen("\033[31mMalloc error.\n\033[0m"));
	else if (code == -5)
		write(1, "\033[31mWrong philosopher number.\n\033[0m",
			utils_strlen("\033[31mWrong philosopher number.\n\033[0m"));
	else if (code == -6)
		;

	exit(0);
}
