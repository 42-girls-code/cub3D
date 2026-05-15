/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:27:11 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/15 14:33:25 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

static int	is_closed(t_game *game, int x, int y);

int	valid_cub_extension(char *path)
{
	int	len;
	int	ret;

	ret = 0;
	if (!path)
		ret = message_erro("Error: invalid file path.");
	else
	{
		len = ft_strlen(path);
		if (len < 4 || ft_strcmp(path + len - 4, ".cub") != 0)
			ret = message_erro("Error: invalid file (.cub)");
	}
	return (ret);
}

int	validate_map_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (ft_strchr("0NSEW", game->map.grid[y][x]))
			{
				if (!is_closed(game, x, y))
					return (message_erro("Error: Map is open!"));
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	is_closed(t_game *game, int x, int y)
{
	if (x == 0 || x == game->map.width -1
		|| y == 0 || y == game->map.height -1)
		return (0);
	if (game->map.grid[y - 1][x] == ' ' || game->map.grid[y + 1][x] == ' '
		|| game->map.grid[y][x - 1] == ' ' || game->map.grid[y][x + 1] == ' ')
		return (0);
	return (1);
}
