/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:02 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/26 23:07:02 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_pix_put(t_my_img *img, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        /* big endian, MSB is the leftmost bit */
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        /* little endian, LSB is the leftmost bit */
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}

void	render_background(t_my_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < 300)
    {
        j = 0;
        while (j < 600)
        {
            img_pix_put(img, j++, i, color);
        }
        ++i;
    }
}

int render_rect(t_my_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

int	render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);
    render_background(&data->img, 0x0000FF);
    render_rect(&data->img, (t_rect){500, 200, 100, 100, 0x00FF00});
    render_rect(&data->img, (t_rect){10, 30, 25, 50, 0xFF0000});
    render_rect(&data->img, (t_rect){10, 30, 60, 10, 0xFF0000});
    render_rect(&data->img, (t_rect){10, 45, 60, 10, 0xFF0000});
    render_rect(&data->img, (t_rect){80, 30, 25, 50, 0xFF0000});
    render_rect(&data->img, (t_rect){115, 30, 25, 50, 0xFF0000});
    render_rect(&data->img, (t_rect){140, 70, 25, 10, 0xFF0000});

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

    return (0);
}