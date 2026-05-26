/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:19:55 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/26 12:06:33 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	init_t_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->config.floor_color = -1;
	game->config.ceiling_color = -1;
	game->state = STATE_INTRO;
}

static void	start_game(t_game *game)
{
	init_mlx(game);
	create_image(game);
	load_intro(game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_loop_hook(game->mlx, render_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (message_erro("Error: no map file provided."));
	init_t_game(&game);
	if (parse_map_file(argv[1], &game))
		exit_error(&game, NULL);
	start_game(&game);
	clean_up(&game);
	return (0);
}

void	print_player_debug(t_game *game) // eliminar
{
	//printf("\033[H\033[J"); // Limpa a tela do terminal
	printf("=== DEBUG CUB3D ===\n");
	printf("Posição Player:  X: [%.3f] | Y: [%.3f]\n",
		game->player.pos_x, game->player.pos_y);
	printf("Vetor Direção:   X: [%.3f] | Y: [%.3f]\n",
		game->player.dir_x, game->player.dir_y);
	printf("Plano Câmera:    X: [%.3f] | Y: [%.3f]\n",
		game->player.plane_x, game->player.plane_y);
	printf("===================\n");
}
