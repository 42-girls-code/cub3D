/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:25:52 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 19:06:22 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_up(t_game *game)
{
	if (!game)
		return ;
	if (game->config.no)
		free(game->config.no);
	if (game->config.so)
		free(game->config.so);
	if (game->config.we)
		free(game->config.we);
	if (game->config.ea)
		free(game->config.ea);
	if (game->map_list)
		ft_lstclear(&game->map_list, free);
	// if (game->map_array)
	// 	free_array(game->map_array);
	//janela mlx
	// mlx_destroy_window();
}
