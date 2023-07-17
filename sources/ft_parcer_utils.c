/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:08:25 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/17 19:37:39 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// verifica o tamanho da linha considerando que a ultima termina com null 

size_t	ft_line_size(char *line)
{
	size_t  i;
    i = 0;
    while (line && line[i] != '\0' && line[i] != '\n')
        i++;
    return (i);
}