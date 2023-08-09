/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:18:41 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/09 15:35:51 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_verify_board(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i]
			!= 'P' && line[i] != 69)
			return (1);
		i++;
	}
	return (0);
}

void	ft_search_button(char *line, int *player, int *coin, int *exit)
{
	int	i;
	int	player_count;
	int	exit_count;
	int	coin_count;

	i = 0;
	player_count = *player;
	coin_count = *coin;
	exit_count = *exit;
	while (line[i])
	{
		if (line[i] == 'P')
			player_count++;
		if (line[i] == 'E')
			exit_count++;
		if (line[i] == 'C')
			coin_count++;
		i++;
	}
	*player = player_count;
	*exit = exit_count;
	*coin = coin_count;
}
