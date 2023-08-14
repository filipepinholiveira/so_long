/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/14 15:30:53 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init(t_map *map)
{
	map->line = 0;
	map->size = 0;
	map->map_size = 0;
	map->new_count = 0;
	map->line_size = 0;
	map->player = 0;
	map->exit = 0;
	map->coin = 0;
	map->count = 0;
	map->moves = 0;
	map->begin_y = 0;
	map->begin_x = 0;
}

int	main(int ac, char **av)
{
	int		fd;
	t_root	game;

	fd = 0;
	init(&game.map);
	if (validate_file(ac, av[1]) == 1)
		return (1);
	if (open_and_count_lines(fd, av[1], &game) == 1)
		return (1);
	if (open_and_parse(fd, av[1], &game) == 1)
		return (1);
	if (open_and_create_arrays (fd, av[1], &game) == 1)
		return (1);
	init_flood_fill(&game);
	flood_fill(game.map.map_teste, game.begin, game.size);
	if (flood_fill_validate(&game) == 1)
		return (1);
	free (game.begin.coin);
	free (game.begin.exit);
	if (initialize_game(&game) == 1)
		return (1);
	mlx_loop_hook(game.data.mlx_ptr, &render, &game);
	mlx_hook(game.data.win_ptr, 2, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.data.win_ptr, 17, 0, &free_mouse, &game);
	mlx_loop(game.data.mlx_ptr);
}
