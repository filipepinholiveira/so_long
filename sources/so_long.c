/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 17:22:57 by fpinho-d         ###   ########.fr       */
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
    t_root root;
    init(&root);
    
    if (ac == 1)
        return (1);
    fd = open(av[1], O_RDONLY);
    root.line = get_next_line(fd);
    root.map_size = -1;
    while (root.line)
    {
        {
            root.map_size++;
            root.line = get_next_line(fd);
        }
    }
    close (fd);
    
    t_root board;
    
    init(&board);
    board.map_size = root.map_size;
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
    free(board.line);

    void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}