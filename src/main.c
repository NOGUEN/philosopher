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
