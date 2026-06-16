/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:14:22 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/20 16:42:55 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Error: mlx_init failed.");
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Cub3D");
	if (!game->win)
		exit_error(game, "Error: mlx_new_window failed.");
}

void	load_intro(t_game *game)
{
	game->intro.img = mlx_xpm_file_to_image(
			game->mlx,
			"assets/cover/cover.xpm",
			&game->intro.width,
			&game->intro.height);
	if (!game->intro.img)
		exit_error(game, "failed loading intro xpm");
}
