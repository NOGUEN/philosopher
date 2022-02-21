NAME = philosopher

FLAG = -Wall -Wextra -Werror

CC = gcc

SRC_PATH = ./src/
INC_PATH = ./include/

FILE = main.c\
	   time.c\
	   init.c\
	   utils.c\
	   check.c\
	   error.c\

SRCS = $(addprefix $(SRC_PATH), $(FILE))
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): philosophers

philosophers:
	@gcc $(FLAG) $(OBJS) -o philosophers -lpthread

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf philosophers

re: fclean all
