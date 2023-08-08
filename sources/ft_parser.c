/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:57:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/08 19:17:43 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    error(char *str, int *count)
{
    
    (*count)++;
    write(1, "Error\n", 6);
    write(1, str, ft_strlen(str));
}

int ft_parser(t_map *board)
{
    
    if (board->line[0] == '\n')
    {
        error("Linha vazia!\n", &board->count);
        return (1);
    }
    if (ft_line_size_cmp(board->line, board->line_size) == 1)
        error("Linhas com tamanho diferente!\n", &board->count);
    if (ft_check_walls(board->line) == 1)
        error("Parede vertical errada!\n", &board->count);
    if (ft_verify_board(board->line) == 1)
        error("Caracter inválido no mapa!\n", &board->count);
    if (board->new_count == 0 || board->new_count == board->map_size)
        if (ft_check_top_bottom_lines(board->line) == 1)
            error("Parede horizontal errada!\n", &board->count);
    if (board->new_count <= board->map_size)
    {
        ft_search_button(board->line, &board->player, &board->coin, &board->exit);
        if (board->new_count == board->map_size)
        {
            if (board->player != 1)
                error("Numero de jogadores inválido!\n", &board->count);
            if (board->exit != 1)
                error("Numero de saidas inválido!\n", &board->count);
            if (board->coin <= 0)
                error("Numero de moedas inválido!\n", &board->count);    
        }
    }
    if (board->new_count == board->map_size && board->count > 0)
        return (1);
    return (0);
}

