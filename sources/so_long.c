/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/11 13:24:16 by fpinho-d         ###   ########.fr       */
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
	if (validate_file(av[1]) == 1) // validar ficheiro .ber
		return (1);
	fd = 0;
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

	// game init

	game.data.mlx_ptr = mlx_init();
	if (game.data.mlx_ptr == NULL)
		return (1);
	game.data.win_ptr = mlx_new_window(game.data.mlx_ptr, 
			game.map.line_size * 64, (game.map.map_size + 1) * 64, "my window");
	if (game.data.win_ptr == NULL)
	{
		free(game.data.win_ptr);
		return (1);
	}
	free (begin.coin);
	free (begin.exit);
	/* Images criation */
	game.wall.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr,
			"assets/wall_brick.xpm", &game.wall.eight, &game.wall.width);
	game.player.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr,
			"assets/male.xpm", &game.player.eight, &game.player.width);
	game.coin.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr,
			"assets/coin.xpm", &game.coin.eight, &game.coin.width);
	game.exit.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr,
			"assets/door_closed.xpm", &game.exit.eight, &game.exit.width);
	game.relva.mlx_img = mlx_xpm_file_to_image(game.data.mlx_ptr,
			"assets/relva.xpm", &game.relva.eight, &game.relva.width);
	// hooks and events
	mlx_loop_hook(game.data.mlx_ptr, &render, &game);
	mlx_hook(game.data.win_ptr, KeyPress, KeyPressMask,
		&handle_keypress, &game);
	mlx_loop(game.data.mlx_ptr);
}

