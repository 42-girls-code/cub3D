/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:25:52 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/26 13:34:35 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_config(t_game *game);
static void	clean_textures(t_game *game);
static void	clean_mlx(t_game *game);

void	clean_up(t_game *game)
{
	if (!game)
		return ;
	clean_config(game);
	clean_textures(game);
	clean_mlx(game);
}

static void	clean_config(t_game *game)
{
	free(game->config.no);
	free(game->config.so);
	free(game->config.we);
	free(game->config.ea);
	if (game->map_list)
		ft_lstclear(&game->map_list, free);
	if (game->map.grid)
		free_array(game->map.grid);
}

static void	clean_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
}

static void	clean_mlx(t_game *game)
{
	if (game->intro.img)
		mlx_destroy_image(game->mlx, game->intro.img);
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
