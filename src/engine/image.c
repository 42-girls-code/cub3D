/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:03:38 by cris              #+#    #+#             */
/*   Updated: 2026/05/25 15:05:14 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_game *game)
{
	game->frame.width = SCREEN_WIDTH;
	game->frame.height = SCREEN_HEIGHT;
	game->frame.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->frame.img)
		exit_error(game, "Error: mlx_new_image failed.");
	game->frame.addr = mlx_get_data_addr(
			game->frame.img,
			&game->frame.bpp,
			&game->frame.line_len,
			&game->frame.endian
			);
}
