/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:03:29 by ingrid            #+#    #+#             */
/*   Updated: 2026/06/08 17:48:35 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->mouse_x == -1)
	{
		game->mouse_x = x;
		return (0);
	}
	game->mouse_delta += x - game->mouse_x;
	game->mouse_x = x;
	return (0);
}
