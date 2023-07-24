/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:57:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 12:38:57 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// vou tentar criar parcer com todas as verificaçoes
// verificar se linhas tem todas o mesmo comprimento - feito
// verificar se 1a e ultima sao feitas apenas de paredes '1' - feito
// verificar se paredes verticais sao feitas apenas de parede '1' - feito
// verificar se tem apenas um player 'P' - a fazer
// verificar se tem apenas uma saida 'E' - a fazer

int ft_parcer(char *line, size_t size, int count, int new_count, int player, int exit)
{
    if (ft_line_size_cmp(line, size) == 1)
    {
        write(1, "Erro:\nLinhas com tamanho diferente!\n", 37);
        return (1);
    }
    if (ft_check_walls(line) == 1)
    {
        write (1, "Erro:\nParede vertical errada!\n", 29);
        return (1);
    }
    if (new_count == 0 || new_count == count)
    {
        if (ft_check_top_bottom_lines(line) == 1)
        {
            write(1, "Erro:\nParede horizontal errada!\n", 31);
            return (1);
        }
    }
    if (new_count <= count)
    {   
        int player_count;
        int exit_count;

        player_count += player;
        exit_count += exit;
        player = ft_search_player_button(line);
        exit = ft_search_exit_button(line);
        if (new_count == count)
        {
            if (player_count != 1)
            {
                write(1, "Erro:\nNumero de jogadores inválido!\n", 36);
                return (1);
            }
            if (exit_count != 1)
            {
                write(1, "Erro:\nNumero de saidas inválido!\n", 33);
                return (1);
            }
        }
    }
    printf("Valor de P:%d\n", player);
    printf("Valor de E:%d\n", exit);
    return (0);
}

