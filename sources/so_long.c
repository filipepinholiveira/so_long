/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/11 13:53:39 by fpinho-d         ###   ########.fr       */
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
	init(&game.map);

	if (ac == 1)
		return (1);
	fd = 0;
	if (validate_file(av[1]) == 1) // validar ficheiro .ber
		return (1);
	if (open_and_count_lines(fd, av[1], &game) == 1) // contar tamanho do texto em linhas
		return (1);
	if (open_and_parse(fd, av[1], &game) == 1) // loop para verificar cada linha com o parser
		return (1);
	if (open_and_create_arrays (fd, av[1], &game) == 1) // preencher os mapas para flood fill e para janela de jogo
		return (1);

	// flood fill

	t_point	begin;
	t_point	size;
	begin.x = game.map.begin_x;
	begin.y = game.map.begin_y;
	begin.coin = malloc (sizeof(int));
	*begin.coin = 0;
	begin.exit = malloc (sizeof(int));
	*begin.exit = 0;
	size.x = game.map.line_size;
	size.y = game.map.map_size;
	flood_fill(game.map.map_teste, begin, size);
	if (*begin.coin != game.map.coin || *begin.exit != game.map.exit)
	{
		int	p;
		
		p = 0;
		write(1, "Error\nFlood fill!\n", 19);
		free (begin.coin);
		free (begin.exit);
		while (p <= game.map.map_size)
		{
			if (game.map.map[p])
				free(game.map.map[p]);
			if (game.map.map_teste[p])
				free(game.map.map_teste[p]);
			p++;
		}
		free(game.map.map_teste);
		free(game.map.map);
		return (1);
	}
	free (begin.coin);
	free (begin.exit);
	if (initialize_game(&game) == 1) // game init
		return (1);
	mlx_loop_hook(game.data.mlx_ptr, &render, &game); // hooks and events
	mlx_hook(game.data.win_ptr, KeyPress, KeyPressMask,
		&handle_keypress, &game); // hooks and events
	mlx_loop(game.data.mlx_ptr);
}

