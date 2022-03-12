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

void	check_must_eat(t_all *all)
{
	int	i;

	i = -1;
	if (all->must_eat_number != 0)
	{
		while (++i < all->philo_number)
		{
			if (all->philos[i].eat_cnt >= all->must_eat_number)
				i++;
			else
				break ;
		}
		if (i == all->philo_number)
			all->eat_flag = 1;
	}
}
