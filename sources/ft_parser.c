/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:57:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/27 17:56:18 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// vou tentar criar parcer com todas as verificaçoes
// verificar se linhas tem todas o mesmo comprimento - feito
// verificar se 1a e ultima sao feitas apenas de paredes '1' - feito
// verificar se paredes verticais sao feitas apenas de parede '1' - feito
// verificar se tem apenas um player 'P' - feito
// verificar se tem apenas uma saida 'E' - feito
// verificar se tem caracteres diferentes de '0' '1' 'P' 'E' - a fazer

int ft_parser(t_map *board)
{
    int count;

    count = 0;
    if (ft_line_size_cmp(board->line, board->line_size) == 1)
    {
        write(1, "Error:\nLinhas com tamanho diferente!\n", 37);
        count++;
    }
    if (ft_check_walls(board->line) == 1)
    {
        write (1, "Error:\nParede vertical errada!\n", 31);
        count++;
    }
    if (ft_verify_board(board->line) == 1)
    {
        write(1, "Error:\nCaracter inválido no mapa!\n", 35);
        count++;
    }
    if (board->new_count == 0 || board->new_count == board->map_size)
    {
        if (ft_check_top_bottom_lines(board->line) == 1)
        {
            write(1, "Error:\nParede horizontal errada!\n", 33);
            count++;
        }
    }
    if (board->new_count <= board->map_size)
    {   
        ft_search_button(board->line, &board->player, &board->coin, &board->exit);
        if (board->new_count == board->map_size)
        {
            if (board->player != 1)
            {
                write(1, "Error:\nNumero de jogadores inválido!\n", 38);
                count++;
            }
            if (board->exit != 1)
            {
                write(1, "Error:\nNumero de saidas inválido!\n", 34);
                count++;
            }
        }
    if (board->new_count == board->map_size && count > 0)
        return (1);
    }
    return (0);
}

