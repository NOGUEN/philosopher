/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noguen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:14:59 by noguen            #+#    #+#             */
/*   Updated: 2022/02/21 19:05:58 by noguen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

size_t	utils_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	utils_atoi(const char *str)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - 48);
	return (result * sign);
}

int	utils_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	utils_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!utils_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	utils_putnbr(long long num)
{
	char	c;

	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	if (num < 10)
	{
		c = num + 48;
		write(1, &c, 1);
	}
	else
	{
		utils_putnbr(num / 10);
		utils_putnbr(num % 10);
	}
}
