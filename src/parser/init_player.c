/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:13:03 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/26 12:07:19 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_direction(t_game *game)
{
	char	dir;

	dir = game->player.dir;
	if (dir == 'N')
	{
		game->player.dir_y = -1.0;
		game->player.plane_x = 0.66;
	}
	else if (dir == 'S')
	{
		game->player.dir_y = 1.0;
		game->player.plane_x = -0.66;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.plane_y = -0.66;
	}
}

void	save_player_info(t_game *game, char direction, int x)
{
	game->player.pos_y = (double)ft_lstsize(game->map_list) + 0.5;
	game->player.pos_x = (double)x + 0.5;
	game->player.dir = direction;
	game->player_count++;
	init_player_direction(game);
}
