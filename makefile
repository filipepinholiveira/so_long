MAND = so_long.c 
OBJ_MAND = $(MAND:.c=.o)
CFLAGS = -Wall -Extra -Werror -g

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ_MAND)
	CC -g -Imlx -c $(CFLAGS) $(OBJ_MAND) -o $(NAME)

clean:
	rm -rf $(OBJ_MAND)

fclean: clean
	rm -rf $(NAME)

re: fclean all