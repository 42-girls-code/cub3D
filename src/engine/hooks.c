/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:09:58 by ingrid            #+#    #+#             */
/*   Updated: 2026/06/09 14:22:54 by ingrid           ###   ########.fr       */
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
		game->mouse_x = -1;
	}
}

int	handle_close(t_game *game)
{
	clean_up(game);
	exit(0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_close(game);
	if (game->state == STATE_INTRO)
		handle_intro(keycode, game);
	else if (game->state == STATE_PLAYING)
	{
		if (keycode == W)
			game->keys.w = 1;
		if (keycode == S)
			game->keys.s = 1;
		if (keycode == A)
			game->keys.a = 1;
		if (keycode == D)
			game->keys.d = 1;
		if (keycode == RIGHT_ARROW)
			game->keys.right = 1;
		if (keycode == LEFT_ARROW)
			game->keys.left = 1;
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (game->state == STATE_PLAYING)
	{
		if (keycode == W)
			game->keys.w = 0;
		if (keycode == S)
			game->keys.s = 0;
		if (keycode == A)
			game->keys.a = 0;
		if (keycode == D)
			game->keys.d = 0;
		if (keycode == RIGHT_ARROW)
			game->keys.right = 0;
		if (keycode == LEFT_ARROW)
			game->keys.left = 0;
	}
	return (0);
}

void	update_player_position(t_game *game)
{
	if (game->keys.w)
		move_player_forward_back(game, MOVE_SPEED);
	if (game->keys.s)
		move_player_forward_back(game, -MOVE_SPEED);
	if (game->keys.a)
		move_player_sideways(game, -MOVE_SPEED);
	if (game->keys.d)
		move_player_sideways(game, MOVE_SPEED);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
}
