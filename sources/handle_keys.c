/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:40 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/09 15:46:37 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_key_down(int *keysym, t_root *game)
{
	if (game->map.map[game->player.begin_y + 1][game->player.begin_x] == 'C')
		game->map.coin = game->map.coin - 1;
	if (game->map.map[game->player.begin_y + 1][game->player.begin_x]
		== 'E' && game->map.coin == 0)
	{
		game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_y = game->player.begin_y + 1;
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		*keysym = XK_Escape;
	}
	else if (game->map.map[game->player.begin_y + 1][game->player.begin_x]
		!= '1')
	{
		if (game->map.map[game->player.begin_y][game->player.begin_x]
			== game->map.map[game->exit.begin_y][game->exit.begin_x])
			game->map.map[game->player.begin_y][game->player.begin_x] = 'E';
		else
			game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_y = game->player.begin_y + 1;
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
	}
}

void	handle_key_up(int *keysym, t_root *game)
{
	if (game->map.map[game->player.begin_y - 1][game->player.begin_x] == 'C')
		game->map.coin = game->map.coin - 1;
	if (game->map.map[game->player.begin_y - 1][game->player.begin_x]
		== 'E' && game->map.coin == 0)
	{
		game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_y = game->player.begin_y - 1;
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		*keysym = XK_Escape;
	}
	else if (game->map.map[game->player.begin_y - 1][game->player.begin_x]
		!= '1')
	{
		if (game->map.map[game->player.begin_y][game->player.begin_x]
			== game->map.map[game->exit.begin_y][game->exit.begin_x])
			game->map.map[game->player.begin_y][game->player.begin_x] = 'E';
		else
			game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_y = game->player.begin_y - 1;
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
	}
}

void	handle_key_left(int *keysym, t_root *game)
{
	if (game->map.map[game->player.begin_y][game->player.begin_x - 1] == 'C')
		game->map.coin = game->map.coin - 1;
	if (game->map.map[game->player.begin_y][game->player.begin_x - 1]
			== 'E' && game->map.coin == 0)
	{
		game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_x = game->player.begin_x - 1;
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		*keysym = XK_Escape;
	}
	else if (game->map.map[game->player.begin_y][game->player.begin_x - 1]
		!= '1')
	{
		if (game->map.map[game->player.begin_y][game->player.begin_x]
			== game->map.map[game->exit.begin_y][game->exit.begin_x])
			game->map.map[game->player.begin_y][game->player.begin_x] = 'E';
		else
			game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_x = game->player.begin_x - 1;
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
	}
}

void	handle_key_right(int *keysym, t_root *game)
{
	if (game->map.map[game->player.begin_y][game->player.begin_x + 1] == 'C')
		game->map.coin = game->map.coin - 1;
	if (game->map.map[game->player.begin_y][game->player.begin_x + 1]
			== 'E' && game->map.coin == 0)
	{
		game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_x = game->player.begin_x + 1;
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		*keysym = XK_Escape;
	}
	else if (game->map.map[game->player.begin_y][game->player.begin_x + 1]
		!= '1')
	{
		if (game->map.map[game->player.begin_y][game->player.begin_x]
			== game->map.map[game->exit.begin_y][game->exit.begin_x])
			game->map.map[game->player.begin_y][game->player.begin_x] = 'E';
		else
			game->map.map[game->player.begin_y][game->player.begin_x] = '0';
		game->player.begin_x = game->player.begin_x + 1;
		game->map.map[game->player.begin_y][game->player.begin_x] = 'P';
		game->map.moves++;
		ft_printf("Movimentos:%d\n", game->map.moves);
	}
}
