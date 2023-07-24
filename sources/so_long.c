/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/24 11:54:32 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// para ja imprimo o texto e verifico se todas as linhas sao do mesmo tamanho
// e se começam e termina com '1'

// int main(int ac, char **av)
// {
//     int fd;
//     char *line;
//     size_t line_size;
//     int count;
    
//     if (ac == 1)
//         return (1);
//     fd = open(av[1], O_RDONLY);
//     line = get_next_line(fd);
//     line_size = ft_line_size(line);
//     count = -1;
//     while (line)
//     {
//         {
//             //printf("%s", line);
//             if (ft_parcer(line, line_size) == 1)
//             {
//                 free(line);
//                 write(1, "\n", 1);
//                 return (1);
//             }
//             line = get_next_line(fd);
//             count++;
//         }
//     }
//     write(1, "Texto valido\n", 12);
//     write(1, "\n", 1);
//     free(line);
// }

int main(int ac, char **av)
{
    int fd;
    char *line;
    size_t line_size;
    int count;
    
    if (ac == 1)
        return (1);
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    count = -1;
    while (line)
    {
        {
            count++;
            line = get_next_line(fd);
        }
    }
    close (fd);
    
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    line_size = ft_line_size(line);
    int new_count;
    int *player;
    int *exit;

    player = malloc(sizeof(int));
    exit = malloc(sizeof(int));
    new_count = 0;
    (*player) = 0;
    (*exit) = 0;
    while (line)
    {
        {
            if (ft_parcer(line, line_size, count, new_count, *player, *exit) == 1)
            {
                free(line);
                free (player);
                free(exit);
                write(1, "\n", 1);
                return (1);
            }
            line = get_next_line(fd);
            new_count++;
        }
    }
    write(1, "Texto valido\n", 12);
    write(1, "\n", 1);
    free(line);
}