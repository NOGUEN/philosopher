#include "../include/philosophers.h"

long long	time_current(void)
{
	struct timeval	t;
	long long		ms;

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (ms);
}
