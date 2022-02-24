NAME = philosopher

FLAG = -Wall -Wextra -Werror

CC = gcc

SRC_PATH = ./src/
INC_PATH = ./include/

FILE = main.c		\
	   time.c		\
	   init.c		\
	   utils.c		\
	   check.c		\
	   error.c		\
	   philo_act.c	\
	   print.c		\
	   thread.c		\

SRCS = $(addprefix $(SRC_PATH), $(FILE))
all: $(NAME)

$(NAME): philosophers

philosophers: $(OBJS)
	@gcc $(FLAG) $(SRCS) -o philosophers -lpthread

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf philosophers

re: fclean all
