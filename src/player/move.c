/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:09:31 by ingrid            #+#    #+#             */
/*   Updated: 2026/06/09 14:05:17 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_game *game, double x, double y)
{
	char	cell;

	if (x < 0 || y < 0 || (int)x >= game->map.width
		|| (int)y >= game->map.height)
		return (1);
	cell = game->map.grid[(int)y][(int)x];
	if (cell == '1' || cell == ' ')
		return (1);
	return (0);
}

void	move_player_forward_back(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * speed;
	new_y = game->player.pos_y + game->player.dir_y * speed;
	if (!is_wall(game, new_x + PLAYER_RADIUS, game->player.pos_y)
		&& !is_wall(game, new_x - PLAYER_RADIUS, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(game, game->player.pos_x, new_y + PLAYER_RADIUS)
		&& !is_wall(game, game->player.pos_x, new_y - PLAYER_RADIUS))
		game->player.pos_y = new_y;
}

void	move_player_sideways(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.plane_x * speed;
	new_y = game->player.pos_y + game->player.plane_y * speed;
	if (!is_wall(game, new_x + PLAYER_RADIUS, game->player.pos_y)
		&& !is_wall(game, new_x - PLAYER_RADIUS, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(game, game->player.pos_x, new_y + PLAYER_RADIUS)
		&& !is_wall(game, game->player.pos_x, new_y - PLAYER_RADIUS))
		game->player.pos_y = new_y;
}
