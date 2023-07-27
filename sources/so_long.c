/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/27 15:46:07 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    init(t_map *map)
{
    map->line = malloc (sizeof(char));
    map->size = 0;
    map->map_size = 0;
    map->new_count = 0;
    map->line_size = 0;
    map->player = 0;
    map->exit = 0;
    map->coin = 0;
    map->begin_y = 0;
    map->begin_x = 0;
}

int main(int ac, char **av)
{
    int fd;
    t_root game;
    init(&game.map);
    
    if (ac == 1)
        return (1);
    fd = open(av[1], O_RDONLY);
    game.map.line = get_next_line(fd);
    game.map.map_size = -1;
    while (game.map.line)
    {
        {
            game.map.map_size++;
            game.map.line = get_next_line(fd);
        }
    }
    close (fd);
    
    fd = open(av[1], O_RDONLY);
    game.map.line = get_next_line(fd);
    game.map.line_size = ft_line_size(game.map.line);
    
    while (game.map.line)
    {
        {
            if (ft_parser(&game.map) == 1)
            {
                write(1, "\n", 1);
                return (1);
            }
            game.map.line = get_next_line(fd);
            game.map.new_count++;
        }
    }
    close (fd);

    game.map.map = malloc(sizeof(char *) * (game.map.map_size + 1));
    game.map.map_teste = malloc(sizeof(char *) * (game.map.map_size + 1));

    fd = open(av[1], O_RDONLY);
    game.map.line = get_next_line(fd);

    int i;
    int k;
    
    i = 0;
    while (i <= game.map.map_size)
    {   
        k = 0;
        while (game.map.line[k])
        {
            if (game.map.line[k] == 'P')
            {
                game.map.begin_y = i;
                game.map.begin_x = k;
            }
            k++;
        }
        game.map.map[i] = game.map.line;
        game.map.map_teste[i] = ft_strdup(game.map.map[i]);
        game.map.line = get_next_line(fd);
        i++;
    }
    
    //int j = 0;
    t_point begin;
    t_point size;

    begin.x = game.map.begin_x;
    begin.y = game.map.begin_y;
    
    begin.coin = malloc (sizeof(int));
    *begin.coin = 0;
    begin.exit = malloc (sizeof(int));
    *begin.exit = 0;
    size.x = game.map.line_size;
    size.y = game.map.map_size;
    flood_fill(game.map.map_teste, begin, size);
    if (*begin.coin != game.map.coin || *begin.exit != game.map.exit)
    {
        write(1, "Erro:\nFlood fill!\n", 19);
        return (1);
    }
    write(1, "Texto valido\n", 12);
    write(1, "\n", 1);
    
    game.data.mlx_ptr = mlx_init();
    if (game.data.mlx_ptr == NULL)
        return (1);
    game.data.win_ptr = mlx_new_window(game.data.mlx_ptr, game.map.line_size * 64, (game.map.map_size + 1) * 64, "my window");
    if (game.data.win_ptr == NULL)
    {
        free(game.data.win_ptr);
        return (1);
    }

    /* Setup hooks */
    game.wall.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr, "assets/male.xpm", &game.wall.eight, &game.wall.width);
    mlx_loop_hook(game.data.mlx_ptr, &render, &game);
    mlx_hook(game.data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);

    mlx_loop(game.data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(game.data.mlx_ptr);
    free(game.data.mlx_ptr);
}