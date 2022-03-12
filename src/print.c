#include "../include/philosophers.h"

void	print_error(char *str)
{
	write(1, "\033[31m", utils_strlen("\033[31m"));
	write(1, str, utils_strlen(str));
	write(1, "\n\033[0m", utils_strlen("\n\033[0m"));
}

void	print_log(t_all *all, char *str, int id)
{
	long long	time;

	pthread_mutex_lock(&(all->printing));
	time = time_current() - all->base_time;
	if (!all->death_flag)
	{
		write(1, "\033[", utils_strlen("\033["));
		utils_putnbr(32 + (id + 1) % 5);
		write(1, "m", 1);
		utils_putnbr(time);
		write(1, " ", 1);
		utils_putnbr(id + 1);
		write(1, " ", 1);
		write(1, str, utils_strlen(str));
		write(1, "\n\033[0m", utils_strlen("\n\033[0m"));
	}
	pthread_mutex_unlock(&(all->printing));
}
