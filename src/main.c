/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:19:55 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/21 20:20:22 by cris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	init_t_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->config.floor_color = -1;
	game->config.ceiling_color = -1;
	game->config.count = 0;
	game->state = STATE_INTRO;
}

static void	start_game(t_game *game)
{
	init_mlx(game);
	create_image(game);
	load_intro(game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
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
