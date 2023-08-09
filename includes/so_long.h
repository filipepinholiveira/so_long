/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:08 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/09 18:18:44 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../sources/GET_NEXT_LINE/get_next_line.h"
#include "../sources/PRINTF/ft_printf.h"
#include "../mlx_linux/mlx_int.h"
#include "../mlx_linux/mlx.h"

typedef struct s_map
{
	char *line;
	size_t size;
	int map_size;
	int new_count;
	int line_size;
	int player;
	int exit;
	int coin;
	int begin_x;
	int begin_y;
	int count;
	int moves;
	char **map;
	char **map_teste;
		
} t_map;

typedef struct s_point
{
	int y;
	int x;
	int *coin;
	int *exit;
	
} t_point;

typedef struct s_my_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	int 	begin_x;
	int 	begin_y;
	t_point	begin;
	int		width;
	int		eight;
}	t_my_img;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

typedef struct s_root
{
	t_map map;
	t_data data;
	t_point coin_exit;
	t_my_img wall;
	t_my_img player;
	t_my_img exit;
	t_my_img relva;
	t_my_img coin;
	t_my_img enemy;
}	t_root;


// sources - parcer.c

int ft_parser(t_map *board);

// sources - main_utils.c

int	open_and_count_lines(int fd, const char *av, t_root game);

// sources - parcer_utils.c
size_t	ft_line_size(char *line);
int ft_line_size_cmp(char *line, size_t line_size);
int ft_check_walls(char *line);
int ft_check_top_bottom_lines(char *lines);

// sources - parcer_utils2.c
int    ft_search_player_button(char *line);
int    ft_search_exit_button(char *line);
int ft_verify_board(char *line);
void ft_search_button(char *line, int *player, int *coin, int *exit);

// sources - flood_fill.c

void	flood_fill(char **tab, t_point begin, t_point size);

// sources - ft_strdup.c

char	*ft_strdup(char *s);

// sources - mlx_lib_utils.c

int	handle_keypress(int keysym, t_root *game);

// sources - handle_keys.c

void	handle_key_down(int *keysym, t_root *game);
void    handle_key_up(int *keysym, t_root *game);
void handle_key_left(int *keysym, t_root *game);
void handle_key_right(int *keysym, t_root *game);

// sources - render_utils.c

int	key_hook(int keysym, t_root *game);
int	render(t_root *game);

// sources - free_map.c

void	free_all(t_root *game);

#endif