

MAND = sources/so_long.c \
sources/ft_parcer.c \
sources/ft_parcer_utils.c \
sources/ft_parcer_utils2.c \
sources/GET_NEXT_LINE/get_next_line.c \
sources/GET_NEXT_LINE/get_next_line_utils.c \


CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

MINILIBX = ./mlx_linux/libmlx.a

OBJ_MAND = $(MAND:.c=.o)

all: $(NAME)

MINILIBX:
	$(MAKE) -C mlx_linux

$(NAME): $(OBJ_MAND) MINILIBX
	cc $(OBJ_MAND) -L./mlx_linux $(CFLAGS) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

clean:
	rm -f $(OBJ_MAND) 

fclean: clean
	rm -f $(NAME) $(MINILIBX)

re: fclean all