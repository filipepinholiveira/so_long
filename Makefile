

MAND = sources/so_long.c \
	sources/ft_parser.c \
	sources/ft_parser_utils.c \
	sources/ft_parser_utils2.c \
	sources/ft_strdup.c \
	sources/flood_fill.c \
	sources/mlx_lib_utils.c \
	sources/render_utils.c \
	sources/free_map.c \
	sources/GET_NEXT_LINE/get_next_line.c \
	sources/GET_NEXT_LINE/get_next_line_utils.c


CFLAGS = -Wall -Wextra -Werror -g3# -fsanitize=address

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