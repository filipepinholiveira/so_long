/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_lib_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:13:27 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/09 15:47:39 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_root *game)
{
	if (keysym == XK_Down)
		handle_key_down(&keysym, game);
	if (keysym == XK_Up)
		handle_key_up(&keysym, game);
	if (keysym == XK_Left)
		handle_key_left(&keysym, game);
	if (keysym == XK_Right)
		handle_key_right(&keysym, game);
	if (game->map.coin == 0)
	{
		mlx_destroy_image(game->data.mlx_ptr, game->exit.mlx_img);
		game->exit.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr, \
		"assets/porta_aberta.xpm", &game->exit.eight, &game->exit.width);
	}
	if (keysym == XK_Escape)
	{
		free_all(game);
	}
	return (0);
}
