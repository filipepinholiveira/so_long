/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/08 19:28:09 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// erro com mapa com ficheiro vazio:


// erro: aceita caracteres invalidos




void    init(t_map *map)
{
    map->line = 0;
    map->size = 0;
    map->map_size = 0;
    map->new_count = 0;
    map->line_size = 0;
    map->player = 0;
    map->exit = 0;
    map->coin = 0;
    map->count = 0;
    map->begin_y = 0;
    map->begin_x = 0;
}

int main(int ac, char **av)
{
    // loop para verificar numero de linhas
    int fd;
    t_root game;
    init(&game.map);
    int len;
    
    if (ac == 1)
        return (1);
    len = ft_strlen(av[1]);
    if (av[1][len-1] != 'r' || av[1][len-2] != 'e' || av[1][len-3] != 'b' || av[1][len-4] != '.')
        return (1);
    fd = open(av[1], O_RDONLY);
    game.map.line = get_next_line(fd);
    if (game.map.line == NULL)
    {   
        write(1, "Error\nempty file!\n", 18);
        return (1);
    }
    game.map.map_size = -1;
    while (game.map.line)
    {
        free(game.map.line);
        {
            game.map.map_size++;
            game.map.line = get_next_line(fd);
        }
    }
    close (fd);

    // loop para verificar cada linha com o parser
    
    fd = open(av[1], O_RDONLY);
    game.map.line = get_next_line(fd);
    game.map.line_size = ft_line_size(game.map.line);
    
    int f;

    f = 0;
    while (game.map.line)
    {
        {
            if (ft_parser(&game.map) == 1)
            {
                f = 1;
                free (game.map.line);
                game.map.line = NULL;
                write(1, "\n", 1);
            }
            if (game.map.line)
                free(game.map.line);
            game.map.line = get_next_line(fd);
            game.map.new_count++;
        }
    }
    if (f == 1)
        return(1);
    close (fd);
        
    // preencher os mapas para flood fill e para janela de jogo

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
        int p;

        p = 0;
        write(1, "Error\nFlood fill!\n", 19);
        free (begin.coin);
        free (begin.exit);
        while (p <= game.map.map_size)
        {       
            if (game.map.map[p])
                    free(game.map.map[p]);
            if (game.map.map_teste[p])
                    free(game.map.map_teste[p]);
            p++;
        }
        free(game.map.map_teste);
        free(game.map.map);
        
        return (1);
    }
    // write(1, "Texto valido\n", 12);
    // write(1, "\n", 1);
    
    game.data.mlx_ptr = mlx_init();
    if (game.data.mlx_ptr == NULL)
        return (1);
    game.data.win_ptr = mlx_new_window(game.data.mlx_ptr, game.map.line_size * 64, (game.map.map_size + 1) * 64, "my window");
    if (game.data.win_ptr == NULL)
    {
        free(game.data.win_ptr);
        return (1);
    }
    free (begin.coin);
    free (begin.exit);
    /* Images criation */
    game.wall.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr, "assets/wall_brick.xpm", &game.wall.eight, &game.wall.width);
    game.player.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr, "assets/male.xpm", &game.player.eight, &game.player.width);
    game.coin.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr, "assets/coin.xpm", &game.coin.eight, &game.coin.width);
    game.exit.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr, "assets/door_closed.xpm", &game.exit.eight, &game.exit.width);
    game.relva.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr, "assets/relva.xpm", &game.relva.eight, &game.relva.width);
    
    // hooks and events
    mlx_loop_hook(game.data.mlx_ptr, &render, &game);
    mlx_hook(game.data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);

    mlx_loop(game.data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    //free_all(game);
}
