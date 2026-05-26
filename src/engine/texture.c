/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:04:00 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/26 13:35:35 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static char	*get_texture_path(t_game *game, int idx);

int	load_game_texture(t_game *game)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 4)
	{
		path = get_texture_path(game, i);
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx, path,
				&game->textures[i].width, &game->textures[i].height);
		if (!game->textures[i].img)
			return (1);
		game->textures[i].addr = mlx_get_data_addr(
				game->textures[i].img,
				&game->textures[i].bpp,
				&game->textures[i].line_len,
				&game->textures[i].endian);
		i++;
	}
	return (0);
}

static char	*get_texture_path(t_game *game, int idx)
{
	if (idx == NORTH)
		return (game->config.no);
	if (idx == SOUTH)
		return (game->config.so);
	if (idx == WEST)
		return (game->config.we);
	if (idx == EAST)
		return (game->config.ea);
	return (NULL);
}
