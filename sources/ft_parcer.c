/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:57:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 16:42:00 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// vou tentar criar parcer com todas as verificaçoes
// verificar se linhas tem todas o mesmo comprimento - feito
// verificar se 1a e ultima sao feitas apenas de paredes '1' - feito
// verificar se paredes verticais sao feitas apenas de parede '1' - feito
// verificar se tem apenas um player 'P' - a fazer
// verificar se tem apenas uma saida 'E' - a fazer

int ft_parcer(t_root *board)
{
    if (ft_line_size_cmp(board->line, board->line_size) == 1)
    {
        write(1, "Erro:\nLinhas com tamanho diferente!\n", 37);
        return (1);
    }
    if (ft_check_walls(board->line) == 1)
    {
        write (1, "Erro:\nParede vertical errada!\n", 29);
        return (1);
    }
    if (board->new_count == 0 || board->new_count == board->map_size)
    {
        if (ft_check_top_bottom_lines(board->line) == 1)
        {
            write(1, "Erro:\nParede horizontal errada!\n", 31);
            return (1);
        }
    }
    if (board->new_count <= board->map_size)
    {   
    
        board->player += ft_search_player_button(board->line);
        board->exit += ft_search_exit_button(board->line);
        if (board->new_count == board->map_size)
        {
            if (board->player != 1)
            {
                write(1, "Erro:\nNumero de jogadores inválido!\n", 36);
                return (1);
            }
            if (board->exit != 1)
            {
                write(1, "Erro:\nNumero de saidas inválido!\n", 33);
                return (1);
            }
        }
    }
    return (0);
}

