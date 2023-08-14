/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:35:47 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/14 14:59:16 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill_validate(t_root *game)
{
	int	p;

	p = 0;
	if (*game->begin.coin != game->map.coin || *game->begin.exit
		!= game->map.exit)
	{
		write(1, "Error\nFlood fill!\n", 19);
		free (game->begin.coin);
		free (game->begin.exit);
		while (p <= game->map.map_size)
		{
			if (game->map.map[p])
				free(game->map.map[p]);
			if (game->map.map_teste[p])
				free(game->map.map_teste[p]);
			p++;
		}
		free(game->map.map_teste);
		free(game->map.map);
		return (1);
	}
	return (0);
}

int	initialize_game(t_root *game)
{
	game->data.mlx_ptr = mlx_init();
	if (game->data.mlx_ptr == NULL)
		return (1);
	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr, 
			game->map.line_size * 64, (game->map.map_size + 1)
			* 64, "my window");
	if (game->data.win_ptr == NULL)
	{
		free(game->data.win_ptr);
		return (1);
	}
	game->wall.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/wall_brick.xpm", &game->wall.eight, &game->wall.width);
	game->player.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/male.xpm", &game->player.eight, &game->player.width);
	game->coin.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/coin.xpm", &game->coin.eight, &game->coin.width);
	game->exit.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/door_closed.xpm", &game->exit.eight, &game->exit.width);
	game->relva.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr,
			"assets/relva.xpm", &game->relva.eight, &game->relva.width);
	return (0);
}
