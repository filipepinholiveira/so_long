/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:05:40 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/11 16:11:29 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_file(int ac, char *av)
{
	int	len;

	if (ac == 1)
		return (1);
	len = ft_strlen(av);
	if (av[len-1] != 'r' || av[len-2] != 'e' || av[len-3] != 'b'
		|| av[len-4] != '.')
	{
		write(1, "Error\ninvalid file!\n", 20);
		return (1);
	}
	return (0);
}
int	open_and_count_lines(int fd, const char *av, t_root *game)
{
	fd = open(av, O_RDONLY);
	game->map.line = get_next_line(fd);
	if (game->map.line == NULL)
	{
		write(1, "Error\nempty file!\n", 18);
		return (1);
	}
	game->map.map_size = -1;
	while (game->map.line)
	{
		free(game->map.line);
		{
			game->map.map_size++;
			game->map.line = get_next_line(fd);
		}
	}
	close (fd);
	return (0);
}

int	open_and_parse(int fd, const char *av, t_root *game)
{
	fd = open(av, O_RDONLY);
	game->map.line = get_next_line(fd);
	game->map.line_size = ft_line_size(game->map.line);
	int		f;

	f = 0;
	while (game->map.line)
	{
		{
			if (ft_parser(&game->map) == 1)
			{
				f = 1;
				free (game->map.line);
				game->map.line = NULL;
				write(1, "\n", 1);
			}
			if (game->map.line)
				free(game->map.line);
			game->map.line = get_next_line(fd);
			game->map.new_count++;
		}
	}
	if (f == 1)
		return (1);
	close (fd);
	return (0);
}
int	open_and_create_arrays(int fd, const char *av, t_root *game)
{
	game->map.map = malloc(sizeof(char *) * (game->map.map_size + 1));
	if (!game->map.map)
		return (1);
	game->map.map_teste = malloc(sizeof(char *) * (game->map.map_size + 1));
	if (!game->map.map_teste)
		return (1);
	fd = open(av, O_RDONLY);
	game->map.line = get_next_line(fd);
	int		i;
	int		k;

	i = 0;
	while (i <= game->map.map_size)
	{
		k = 0;
		while (game->map.line[k])
		{
			if (game->map.line[k] == 'P')
			{
				game->map.begin_y = i;
				game->map.begin_x = k;
			}
			k++;
		}
		game->map.map[i] = game->map.line;
		game->map.map_teste[i] = ft_strdup(game->map.map[i]);
		game->map.line = get_next_line(fd);
		i++;
	}
	return (0);
}
