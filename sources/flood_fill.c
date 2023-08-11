/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:33:43 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/11 16:05:16 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **tab, t_point begin, t_point size)
{
	if (begin.x < 0 || begin.y < 0 || begin.x > size.x || begin.y > size.y)
		return ;
	if (tab[begin.y][begin.x] == '1')
		return ;
	if (tab[begin.y][begin.x] == 'C')
	{
		*begin.coin = *begin.coin + 1;
	}
	if (tab[begin.y][begin.x] == 'E')
	{
		*begin.exit = *begin.exit + 1;
	}
	tab[begin.y][begin.x] = '1';
	flood_fill(tab, (t_point){begin.y - 1, begin.x, begin.coin, begin.exit}, 
		size);
	flood_fill(tab, (t_point){begin.y + 1, begin.x, begin.coin, begin.exit}, 
		size);
	flood_fill(tab, (t_point){begin.y, begin.x - 1, begin.coin, begin.exit}, 
		size);
	flood_fill(tab, (t_point){begin.y, begin.x + 1, begin.coin, begin.exit},
		size);
}

void	init_flood_fill(t_root *game)
{
	game->begin.x = game->map.begin_x;
	game->begin.y = game->map.begin_y;
	game->size.x = game->map.line_size;
	game->size.y = game->map.map_size;
	game->begin.coin = malloc (sizeof(int));
	*game->begin.coin = 0;
	game->begin.exit = malloc (sizeof(int));
	*game->begin.exit = 0;
}
