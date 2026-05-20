/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:20:25 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/20 16:20:46 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game(t_game *game)
{
	if (game->state == STATE_INTRO)
		mlx_put_image_to_window(game->mlx, game->win, game->intro.img, 0, 0);
	else if (game->state == STATE_PLAYING)
		return (0);
	return (0);
}
