/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:43:08 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/17 19:36:00 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../sources/GET_NEXT_LINE/get_next_line.h"
#include "../mlx_linux/mlx_int.h"
#include "../mlx_linux/mlx.h"

// sources
size_t	ft_line_size(char *line);
int ft_parcer(char *line, size_t size);
#endif