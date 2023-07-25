/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:08 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/25 18:45:25 by fpinho-d         ###   ########.fr       */
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
#include "../mlx_linux/mlx_int.h"
#include "../mlx_linux/mlx.h"

typedef struct s_root
{
	char *line;
	size_t size;
	int map_size;
	int new_count;
	int line_size;
	int player;
	int exit;
	int begin_x;
	int begin_y;
		
} t_root;

typedef struct s_point
{
	int y;
	int x;
	
} t_point;

// sources - parcer.c

int ft_parcer(t_root *board);


// sources - parcer_utils.c
size_t	ft_line_size(char *line);
int ft_line_size_cmp(char *line, size_t line_size);
int ft_check_walls(char *line);
int ft_check_top_bottom_lines(char *lines);

// sources - parcer_utils2.c
int    ft_search_player_button(char *line);
int    ft_search_exit_button(char *line);
int ft_verify_board(char *line);

// sources - flood_fill.c

void	flood_fill(char **tab, t_point begin, t_point size);

// sources - ft_strdup.c

char	*ft_strdup(char *s);

#endif