

MAND = sources/so_long.c
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

MINILIBX = ./mlx_linux/libmlx.a

OBJ_MAND = $(MAND:.c=.o)

all: $(NAME) $(MINILIBX)

$(MINILIBX):
	make -C mlx_linux

$(NAME): $(OBJ_MAND)
	cc -g -C $(CFLAGS) $(OBJ_MAND) -o $(NAME)

clean:
	rm -rf $(OBJ_MAND) 

fclean: clean
	rm -rf $(NAME) $(MINILIBX)

re: fclean all