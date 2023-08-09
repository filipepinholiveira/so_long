/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:02 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/09 17:44:12 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render(t_root *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i <= game->map.map_size)
	{
		while (k < game->map.line_size)
		{
			if (game->map.map[i][k] == '1')
				mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, 
					game->wall.mlx_img, k * 64, i * 64);
			if (game->map.map[i][k] == '0')
				mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, 
					game->relva.mlx_img, k * 64, i * 64);
			if (game->map.map[i][k] == 'P')
			{
				mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, 
					game->player.mlx_img, k * 64, i * 64);
				game->player.begin = (t_point){i, k, NULL, NULL};
			}
			if (game->map.map[i][k] == 'C')
				mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, 
					game->coin.mlx_img, k * 64, i * 64);
			if (game->map.map[i][k] == 'E')
			{
				mlx_put_image_to_window(game->data.mlx_ptr, game->data.win_ptr, 
					game->exit.mlx_img, k * 64, i * 64);
				game->exit.begin_x = k;
				game->exit.begin_y = i;
			}
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}
