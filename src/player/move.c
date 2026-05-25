/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:09:31 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/25 15:10:59 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_forward_back(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * speed;
	new_y = game->player.pos_y + game->player.dir_y * speed;
	if ((int)new_x >= 0 && (int)new_x < game->map.width)
	{
		if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
			game->player.pos_x = new_x;
	}
	if ((int)new_y >= 0 && (int) new_y < game->map.height)
	{
		if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
			game->player.pos_y = new_y;
	}
}

void	move_player_strafe(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.plane_x * speed;
	new_y = game->player.pos_y + game->player.plane_y * speed;
	if ((int)new_x >= 0 && (int)new_x < game->map.width)
	{
		if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
			game->player.pos_x = new_x;
	}
	if ((int)new_y >= 0 && (int) new_y < game->map.height)
	{
		if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
			game->player.pos_y = new_y;
	}
}
