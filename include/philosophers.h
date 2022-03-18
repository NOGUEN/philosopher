#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_idx;
	int				right_fork_idx;
	int				eat_cnt;
	long long		time;
	struct s_all	*all;
	pthread_mutex_t protect;
	pthread_t		t_id;
	pthread_t		m_id;
}				t_philo;

typedef struct s_all
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_number;
	int				stop_flag;
	long long		base_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	t_philo			*philos;
}				t_all;

/********about utils********/
size_t		utils_strlen(const char *s);
int			utils_atoi(const char *s);
int			utils_isdigit(int c);
int			utils_isnum(char *str);
void		utils_putnbr(long long num);

/********about init********/
void		init_mutex(t_all *all);
void		init_philosophers(t_all *all);
void		init_all(t_all *all, int argc, char *argv[]);

/********about error********/
void		error_exit(int code);

/********about check********/
int			check_number(char *str);
void		check_init(t_all *all);
int			check_must_eat(t_all *all);
void		check_death(t_all *all, t_philo *philo);

/********about time********/
long long	time_current(void);
void		time_eating(t_all *all);
void		time_sleeping(t_all *all);

/********about thread********/
void		thread_end(t_all *all);
void		*thread_func(void *void_philo);
void		thread_start(t_all *all);

/********about print********/
void		print_error(char *str);
void		print_log(t_philo *philo, char *str);

/********about philo_act********/
void		philo_act_eat(t_philo *philo);
void		philo_act_sleep(t_philo *philo);
void		philo_act_think(t_philo *philo);

#endif
