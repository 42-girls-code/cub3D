/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:09:58 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/21 20:42:25 by cris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_close(t_game *game)
{
	clean_up(game);
	exit (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_close(game);
	if (game->state == STATE_INTRO
	&& (keycode == ENTER_MAIN
		|| keycode == ENTER_NUMPAD))
	{
		game->state = STATE_PLAYING;
		mlx_destroy_image(game->mlx, game->intro.img);
		game->intro.img = NULL;
		return (0);
	}
	if (game->state == STATE_PLAYING)
	{
		if (keycode == W)
			printf("Falta implentar W, keycode: %d\n", keycode);
		else if (keycode == S)
			printf("Falta implentar S, keycode: %d\n", keycode);
		else if (keycode == A)
			printf("Falta implentar A, keycode: %d\n", keycode);
		else if (keycode == D)
			printf("Falta implentar D, keycode: %d\n", keycode);
		else if (keycode == RIGHT_ARROW)
			printf("Falta implentar ->, keycode: %d\n", keycode);
		else if (keycode == LEFT_ARROW)
			printf("Falta implentar <-, keycode: %d\n", keycode);
	}
	return (0);
}
