/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:05:40 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/09 18:21:03 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_and_count_lines(int fd, const char *av, t_root game)
{
	fd = open(&av[1], O_RDONLY);
	game.map.line = get_next_line(fd);
	if (game.map.line == NULL)
	{
		write(1, "Error\nempty file!\n", 18);
		return (1);
	}
	game.map.map_size = -1;
	while (game.map.line)
	{
		free(game.map.line);
		{
			game.map.map_size++;
			game.map.line = get_next_line(fd);
		}
	}
	close (fd);
	return (0);
}