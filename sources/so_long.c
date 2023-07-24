/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 16:09:08 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// para ja imprimo o texto e verifico se todas as linhas sao do mesmo tamanho
// e se começam e termina com '1'



void    init(t_root *board)
{

    board->line = malloc (sizeof(char));
    board->size = 0;
    board->map_size = 0;
    board->new_count = 0;
    board->line_size = 0;
    board->player = 0;
    board->exit = 0;
    board->begin_y = 2;
    board->begin_x = 6;
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
            if (ft_parcer(&board) == 1)
            {
                write(1, "\n", 1);
                return (1);
            }
            board.line = get_next_line(fd);
            board.new_count++;
        }
    }
    write(1, "Texto valido\n", 12);
    write(1, "\n", 1);
    close (fd);

    // criar array bidimensional abrindo de novo o ficheiro, fazendo gnl e malloc de cada linha
    char ** board_print;
    char ** board_test;

    board_print = malloc(sizeof(char *) * (board.map_size));
    board_test = malloc(sizeof(char *) * (board.map_size));

    fd = open(av[1], O_RDONLY);
    board.line = get_next_line(fd);

    int i;

    i = 0;
    while (i <= board.map_size)
    {
        board_print[i] = board.line;
        board_test[i] = ft_strdup(board_print[i]);
        board.line = get_next_line(fd);
        i++;
    }
    int j = 0;
    // while (j <= board.map_size)
    // {
    //     printf("Board Print: %s\n", board_print[j]);
    //     printf("Board Teste: %s\n", board_test[j]);
    //     j++;
    // }

    printf("Tamanho do mapa: %d\n", board.map_size);
    printf("Tamanho da linha: %d\n", board.line_size);
    
    flood_fill(board_test, board);
    while (j <= board.map_size)
    {
        printf("Board Teste: %s\n", board_test[j]);
        j++;
    }

    free(board.line);

    // void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
}