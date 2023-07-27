/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:02 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/27 15:51:07 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	img_pix_put(t_my_img *img, int x, int y, int color)
// {
//     char    *pixel;
//     int		i;

//     i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (img->endian != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
//         i -= 8;
//     }
// }

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
        }
    }
    return (0);
}