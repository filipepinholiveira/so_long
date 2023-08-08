/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:28:37 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/08 14:57:35 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_root *game)
{
        int i;

        i = 0;
	mlx_destroy_image(game->data.mlx_ptr, game->wall.mlx_img);
        mlx_destroy_image(game->data.mlx_ptr, game->player.mlx_img);
        mlx_destroy_image(game->data.mlx_ptr, game->coin.mlx_img);
        mlx_destroy_image(game->data.mlx_ptr, game->exit.mlx_img);
        mlx_destroy_image(game->data.mlx_ptr, game->relva.mlx_img);
        mlx_destroy_window(game->data.mlx_ptr, game->data.win_ptr);
        mlx_destroy_display(game->data.mlx_ptr);
        while (i <= game->map.map_size)
        {       
                if (game->map.map[i])
                        free(game->map.map[i]);
                if (game->map.map_teste[i])
                        free(game->map.map_teste[i]);
                i++;
        }
        free(game->map.map_teste);
        free(game->map.map);
        free(game->map.line);
        free(game->data.mlx_ptr);
        game->data.win_ptr = NULL;
        exit(0);
}
