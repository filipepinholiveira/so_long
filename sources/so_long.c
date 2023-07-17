/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:32 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/17 19:38:49 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// para ja imprimo o texto e verifico se todas as linhas sao do mesmo tamanho

int main(int ac, char **av)
{
    int fd;
    char *line;
    size_t line_size;
    if (ac == 1)
        return (1);
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    line_size = ft_line_size(line);
    while (line)
    {
        {
            printf("%s", line);
            line = get_next_line(fd);
            if (line && ft_line_size(line) != line_size)
            {	
                printf("linhas com tamanho diferente\n");
                return (1);
            }
        }
    }
    printf("\n");
    free(line);
}
