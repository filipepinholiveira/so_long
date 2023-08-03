/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:02 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/03 13:09:39 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render(t_root *game)
{
    if (game->data.mlx_ptr == NULL)
        return (1);
    for (int i = 0; i <= game->map.map_size; i++)
    {
        for (int k = 0; k < game->map.line_size; k++)
        {
            if (game->map.map[i][k] == '1')
                mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, game->wall.mlx_img, k * 64, i * 64);
            if (game->map.map[i][k] == '0')
                mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, game->relva.mlx_img, k * 64, i * 64);
            if (game->map.map[i][k] == 'P')
            {
                mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, game->player.mlx_img, k * 64, i * 64);
                game->player.begin_x = k;
                game->player.begin_y = i;
            }
            if (game->map.map[i][k] == 'C')
                mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, game->coin.mlx_img, k * 64, i * 64);
            if (game->map.map[i][k] == 'E')
                mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, game->exit.mlx_img, k * 64, i * 64);
        }
    }
    return (0);
}