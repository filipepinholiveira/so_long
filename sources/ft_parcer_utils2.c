/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:18:41 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/25 17:36:15 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_verify_board(char *line)
{
    int i;

    i = 0;
    while (line && line[i] != '\0' && line[i] != '\n')
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'P' && line[i] != 'E')
            return (1);
        i++;
    }
    return (0);
}

int ft_search_player_button(char *line)
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

int ft_search_exit_button(char *line)
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
