/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:33:43 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/25 18:19:55 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	flood_fill(char **tab, t_point begin, t_point size)
{
	if (begin.x < 0 || begin.y < 0 || begin.x > size.x || begin.y > size.y)
		return ;
	if (tab[begin.y][begin.x] == '1')
        return;
	tab[begin.y][begin.x] = '1';
	flood_fill(tab, (t_point){begin.y - 1, begin.x}, size);
	flood_fill(tab, (t_point){begin.y + 1, begin.x}, size);
	flood_fill(tab, (t_point){begin.y, begin.x - 1}, size);
	flood_fill(tab, (t_point){begin.y, begin.x + 1}, size);
}