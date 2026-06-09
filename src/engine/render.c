/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:20:25 by ingrid            #+#    #+#             */
/*   Updated: 2026/06/09 14:14:04 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				put_pixel(&game->frame, x, y,
					game->config.ceiling_color);
			else
				put_pixel(&game->frame, x, y,
					game->config.floor_color);
			x++;
		}
		y++;
	}
}

int	render_game(t_game *game)
{
	if (game->state == STATE_INTRO)
		mlx_put_image_to_window(game->mlx, game->win, game->intro.img, 0, 0);
	else if (game->state == STATE_PLAYING)
	{
		update_player_position(game);
		if (game->mouse_delta)
		{
			rotate_player(game, game->mouse_delta * MOUSE_SENSITIVITY);
			game->mouse_delta = 0.0;
		}
		render_background(game);
		cast_rays(game);
		draw_minimap(game);
		mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	}
	return (0);
}
