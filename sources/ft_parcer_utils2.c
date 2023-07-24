/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:18:41 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 17:08:18 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	fill(char **tab, t_root size, t_root cur, char to_fill)
// {
// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_root){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_root){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_root){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_root){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_root size, t_root begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }

int    ft_search_player_button(char *line)
{
    int i;
    int count_P;

    i = 0;
    count_P = 0;

    while (line[i])
    {
        if (line[i] == 'P')
            count_P++;
        i++;
    }
    //printf("Valor P na funçao: %d\n", count_P);
    return (count_P);
}

int    ft_search_exit_button(char *line)
{
    int i;
    int count_E;

    i = 0;
    count_E = 0;

    while (line[i])
    {
        if (line[i] == 'E')
            count_E++;
        i++;
    }
    //printf("Valor E na funçao: %d\n", count_E);
    return (count_E);
}
