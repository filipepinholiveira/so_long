/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_lib_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:13:27 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/08 14:19:24 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_root *game)
{   
    if (game->map.coin == 0)
        {
            mlx_destroy_image(game->data.mlx_ptr, game->exit.mlx_img);
            game->exit.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr, "assets/porta_aberta.xpm", &game->exit.eight, &game->exit.width);
        }
    if (keysym == XK_Down)
    {   
        if (game->map.map[game->player.begin_y + 1][game->player.begin_x] == 'C')
            game->map.coin = game->map.coin - 1;
        if (game->map.map[game->player.begin_y + 1][game->player.begin_x] == 'E' && game->map.coin == 0)
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_y = game->player.begin_y + 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
            keysym = XK_Escape;
        }
        else if (game->map.map[game->player.begin_y + 1][game->player.begin_x] != '1' &&
        game->map.map[game->player.begin_y + 1][game->player.begin_x] != 'E')
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_y = game->player.begin_y + 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
        }
    }
    if (keysym == XK_Up)
    {   
        if (game->map.map[game->player.begin_y - 1][game->player.begin_x] == 'C')
            game->map.coin = game->map.coin - 1;
        if (game->map.map[game->player.begin_y - 1][game->player.begin_x] == 'E' && game->map.coin == 0)
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_y = game->player.begin_y - 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
            keysym = XK_Escape;
        }
        else if (game->map.map[game->player.begin_y - 1][game->player.begin_x] != '1' &&
        game->map.map[game->player.begin_y - 1][game->player.begin_x] != 'E')
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_y = game->player.begin_y - 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
        }
    }
    if (keysym == XK_Left)
    {   
        if (game->map.map[game->player.begin_y][game->player.begin_x - 1] == 'C')
            game->map.coin = game->map.coin - 1;
        if (game->map.map[game->player.begin_y][game->player.begin_x - 1] == 'E' && game->map.coin == 0)
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_x = game->player.begin_x - 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
            keysym = XK_Escape;
        }
        else if (game->map.map[game->player.begin_y][game->player.begin_x - 1] != '1' && 
        game->map.map[game->player.begin_y][game->player.begin_x - 1] != 'E')
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_x = game->player.begin_x - 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
        }
    }
    if (keysym == XK_Right)
    {   
        if (game->map.map[game->player.begin_y][game->player.begin_x + 1] == 'C')
            game->map.coin = game->map.coin - 1;
        if (game->map.map[game->player.begin_y][game->player.begin_x + 1] == 'E' && game->map.coin == 0)
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_x = game->player.begin_x + 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
            keysym = XK_Escape;
        }
        else if (game->map.map[game->player.begin_y][game->player.begin_x + 1] != '1' &&
        game->map.map[game->player.begin_y][game->player.begin_x + 1] != 'E')
        {
            game->map.map[game->player.begin_y][game->player.begin_x] = '0';
            game->player.begin_x = game->player.begin_x + 1;
            game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
        }
    }
    if (keysym == XK_Escape)
    {
        free_all(game);
        //game->data.win_ptr = NULL;
    }
    return (0);
}
