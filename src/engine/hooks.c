/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:09:58 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/21 21:03:03 by cris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_intro(int keycode, t_game *game)
{
	if (keycode == ENTER_MAIN || keycode == ENTER_NUMPAD)
	{
		game->state = STATE_PLAYING;
		mlx_destroy_image(game->mlx, game->intro.img);
		game->intro.img = NULL;
	}
}

static void	handle_player_input(int keycode, t_game *game)
{
	if (keycode == W)
		printf("Move forward\n");
	else if (keycode == S)
		printf("Move backward\n");
	else if (keycode == A)
		printf("Move left\n");
	else if (keycode == D)
		printf("Move right\n");
	else if (keycode == RIGHT_ARROW)
		printf("Rotate right\n");
	else if (keycode == LEFT_ARROW)
		printf("Rotate left\n");

	(void)game;
}

int	handle_close(t_game *game)
{
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->intro.img)
		mlx_destroy_image(game->mlx, game->intro.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	clean_up(game);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_close(game);

	if (game->state == STATE_INTRO)
		handle_intro(keycode, game);
	else if (game->state == STATE_PLAYING)
		handle_player_input(keycode, game);

	return (0);
}
