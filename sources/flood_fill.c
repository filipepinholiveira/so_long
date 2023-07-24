/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:33:43 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 16:18:35 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(char **tab, t_root board, char to_fill)
{
	tab[board.begin_y][board.begin_x] = 'F';
    (void) to_fill;
	// fill(tab, (t_root){board.begin_x - 1, board.begin_y}, to_fill);
	// fill(tab, (t_root){board.begin_x + 1, board.begin_y}, to_fill);
	// fill(tab, (t_root){board.begin_x, board.begin_y - 1}, to_fill);
	// fill(tab, (t_root){board.begin_x, board.begin_y + 1}, to_fill);
}

void	flood_fill(char **tab, t_root board)
{
	fill(tab, board, 'F');
}