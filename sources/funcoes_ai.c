/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcoes_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:46:20 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/11 12:52:47 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_root	game;
	init(&game.map);
	int		len;

	

	if (!initialize_game(&game))
		return (1);

	// hooks and events
	mlx_loop_hook(game.data.mlx_ptr, &render, &game);
	mlx_hook(game.data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop(game.data.mlx_ptr);
}


Aqui estão algumas das alterações que fiz:

Funções Auxiliares: Separei diferentes partes do código em funções auxiliares para tornar o código mais claro e organizado.

Verificação de Extensão de Arquivo: Criei uma função check_filename_extension para verificar a extensão do arquivo.

Abertura e Validação de Arquivo: Criei uma função open_and_validate_file para lidar com a abertura e validação do arquivo, além de contar o número de linhas.

Parser do Mapa: Criei uma função parse_map para lidar com a análise do mapa e verificação de erros.

Inicialização do Jogo: Criei uma função initialize_game para lidar com a inicialização do jogo, incluindo a alocação de memória e carregamento de imagens.

Redução de Linhas: Reorganizei o código e reduzi algumas redundâncias para ajudar a encurtar a função main.


Claro, aqui está um exemplo de como a função initialize_game poderia ser implementada:


int initialize_game(t_root *game) {
	game->data.mlx_ptr = mlx_init();
	if (game->data.mlx_ptr == NULL) {
		write(1, "Error\nfailed to initialize mlx!\n", 32);
		return 0;
	}

	game->data.win_ptr = mlx_new_window(game->data.mlx_ptr,
		game->map.line_size * 64, (game->map.map_size + 1) * 64, "my window");
	if (game->data.win_ptr == NULL) {
		write(1, "Error\nfailed to create window!\n", 31);
		mlx_destroy_display(game->data.mlx_ptr);
		return 0;
	}

	/* Images creation */
	game->wall.mlx_img = mlx_xpm_file_to_image(game->data.mlx_ptr,
		"assets/wall_brick.xpm", &game->wall.eight, &game->wall.width);
	// Carregar outras imagens aqui

	// Initialize any other game-related data structures here

	return 1; // Successful initialization
}
Essa função cuida da inicialização do jogo, incluindo a criação da janela e o carregamento das imagens necessárias. 
Certifique-se de adaptar o código às suas necessidades específicas e de adicionar o carregamento de outras imagens e 
inicializações necessárias para o seu jogo. Se ocorrer algum erro durante a inicialização, a função retornará 0 para 
indicar que algo deu errado.