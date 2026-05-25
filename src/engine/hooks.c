/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:09:58 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/25 15:42:22 by ingrid           ###   ########.fr       */
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
		move_player_forward_back(game, MOVE_SPEED);
	else if (keycode == S)
		move_player_forward_back(game, -MOVE_SPEED);
	else if (keycode == A)
		move_player_sideways(game, -MOVE_SPEED);
	else if (keycode == D)
		move_player_sideways(game, MOVE_SPEED);
	else if (keycode == RIGHT_ARROW)
		rotate_player(game, ROT_SPEED);
	else if (keycode == LEFT_ARROW)
		rotate_player(game, -ROT_SPEED);
	// printf("\033[H\033[J");
	printf("=== DEBUG CUB3D ===\033[0m\n");
	printf("Posição Player:  X: [%.3f] | Y: [%.3f]\n", game->player.pos_x, game->player.pos_y);
	printf("Vetor Direção:   X: [%.3f] | Y: [%.3f]\n", game->player.dir_x, game->player.dir_y);
	printf("Plano Câmera:    X: [%.3f] | Y: [%.3f]\n", game->player.plane_x, game->player.plane_y);
	printf("===================\n");
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
		handle_player_input(keycode, game);
	return (0);
}
