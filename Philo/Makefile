NAME	= philo

CC		= gcc

#CFLAGS	= -Wall -Wextra -Werror

HEADER	= philo.h

SRC		= 	main.c \
			init_philo.c\
			table_range.c\
			thread_routin.c\
			threads.c \
			time.c	\
			utiles.c \
			actions.c\
			free.c

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	rm -rf $(NAME)
	$(CC) $(CFLAGS) -pthread $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all