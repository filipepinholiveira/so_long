/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:57:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/17 19:25:34 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int ft_parcer(char *line, size_t size)
{
    if (line && ft_line_size(line) != size)
    {	
        printf("linhas com tamanho diferente\n");
        return (1);
    }
    return (0);
}

