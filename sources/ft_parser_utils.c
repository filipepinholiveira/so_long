/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:08:25 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/11 12:52:46 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_top_bottom_lines(char *lines)
{
	int	i;

	i = 0;
	while (lines && lines[i] != '\0' && lines[i] != '\n')
	{
		if (lines[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_walls(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = ft_line_size(line) - 1;
	while (line && line[i] != '\0' && line[i] != '\n')
	{
		if (line[0] != '1' || line[j] != '1')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_line_size(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

int	ft_line_size_cmp(char *line, size_t line_size)
{
	if (line && ft_line_size(line) != line_size)
	{
		return (1);
	}
	return (0);
}
