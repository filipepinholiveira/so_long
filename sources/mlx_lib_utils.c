/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_lib_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:13:27 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/27 15:55:19 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
    /* This function needs to exist, but it is useless for the moment */
    (void) data;
    return (0);
}

int	handle_keypress(int keysym, t_root *game)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_image(game->data.mlx_ptr, game->wall.mlx_img);
        mlx_destroy_window(game->data.mlx_ptr, game->data.win_ptr);
        mlx_destroy_display(game->data.mlx_ptr);
        game->data.win_ptr = NULL;
    }
    return (0);
}
