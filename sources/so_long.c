/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/26 22:35:17 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    init(t_root *board)
{
    board->line = malloc (sizeof(char));
    board->size = 0;
    board->map_size = 0;
    board->new_count = 0;
    board->line_size = 0;
    board->player = 0;
    board->exit = 0;
    board->coin = 0;
    board->begin_y = 0;
    board->begin_x = 0;
}

int main(int ac, char **av)
{
    int fd;
    t_root board;
    init(&board);
    
    if (ac == 1)
        return (1);
    fd = open(av[1], O_RDONLY);
    board.line = get_next_line(fd);
    board.map_size = -1;
    while (board.line)
    {
        {
            board.map_size++;
            board.line = get_next_line(fd);
        }
    }
    close (fd);
    
    fd = open(av[1], O_RDONLY);
    board.line = get_next_line(fd);
    board.line_size = ft_line_size(board.line);
    
    while (board.line)
    {
        {
            if (ft_parser(&board) == 1)
            {
                write(1, "\n", 1);
                return (1);
            }
            board.line = get_next_line(fd);
            board.new_count++;
        }
    }
    close (fd);
    char ** board_print;
    char ** board_test;

    board_print = malloc(sizeof(char *) * (board.map_size + 1));
    board_test = malloc(sizeof(char *) * (board.map_size + 1));

    fd = open(av[1], O_RDONLY);
    board.line = get_next_line(fd);

    int i;
    int k;
    
    i = 0;
    while (i <= board.map_size)
    {   
        k = 0;
        while (board.line[k])
        {
            if (board.line[k] == 'P')
            {
                board.begin_y = i;
                board.begin_x = k;
            }
            k++;
        }
        board_print[i] = board.line;
        board_test[i] = ft_strdup(board_print[i]);
        board.line = get_next_line(fd);
        i++;
    }
    
    //int j = 0;
    t_point begin;
    t_point size;

    begin.x = board.begin_x;
    begin.y = board.begin_y;
    
    begin.coin = malloc (sizeof(int));
    *begin.coin = 0;
    begin.exit = malloc (sizeof(int));
    *begin.exit = 0;
    size.x = board.line_size;
    size.y = board.map_size;
    flood_fill(board_test, begin, size);
    if (*begin.coin != board.coin || *begin.exit != board.exit)
    {
        write(1, "Erro:\nFlood fill!\n", 19);
        return (1);
    }
    write(1, "Texto valido\n", 12);
    write(1, "\n", 1);
    // while (j <= board.map_size)
    // {
    //     printf("Board Print: %s\n", board_print[j]);
    //     j++;
    // }
    // puts("-----------------------------------");
    // j = 0;
    // while (j <= board.map_size)
    // {
    //     printf("Board Teste: %s\n", board_test[j]);
    //     j++;
    // }
    free(board.line);

    t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "my window");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (1);
    }

    /* Setup hooks */
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, 600, 300);
    data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}