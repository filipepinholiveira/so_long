/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/25 18:36:21 by fpinho-d         ###   ########.fr       */
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

    
    char ** board_print;
    char ** board_test;

    board_print = malloc(sizeof(char *) * (board.map_size + 1));
    board_test = malloc(sizeof(char *) * (board.map_size + 1));

    fd = open(av[1], O_RDONLY);
    board.line = get_next_line(fd);

    int i;
    int k;
    
    i = 0;
    printf("board.map_size = %d\n", board.map_size);
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
    
    printf("valor begin y: %d\n", board.begin_y);
    printf("valor begin x: %d\n", board.begin_x);

    
    int j = 0;
    t_point begin;
    t_point size;

    begin.x = board.begin_x;
    begin.y = board.begin_y;
    size.x = board.line_size;
    size.y = board.map_size;
    
    // verificar se caminho encontra saida, e se tem numero de moedas definidas no caminho
    
    flood_fill(board_test, begin, size);
    while (j <= board.map_size)
    {
        printf("Board Teste: %s\n", board_test[j]);
        j++;
    }
    
    

    
    free(board.line);

    void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
    (void) mlx_win;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}