/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 08:31:53 by ingrid            #+#    #+#             */
/*   Updated: 2026/06/11 21:00:39 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "math.h"

#define MM_TILE_SIZE 10
#define MM_COLOR_WALL 0x343A40
#define MM_COLOR_FLOOR 0x0A0A0F
#define MM_COLOR_PLAYER 0x00F5D4
#define MM_COLOR_DIR 0x00BBF9
#define MM_OFFSET 20

static void	draw_minimap_tile(t_img *img, int map_x, int map_y, int color);
static void	draw_minimap_player(t_img *img, t_game *game);
static void	draw_minimap_direction(t_img *img, t_game *game);

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == '1' || game->map.grid[y][x] == ' ')
				draw_minimap_tile(&game->frame, x, y, MM_COLOR_WALL);
			else if (game->map.grid[y][x] == '0'
				|| ft_strchr("NSWE", game->map.grid[y][x]))
				draw_minimap_tile(&game->frame, x, y, MM_COLOR_FLOOR);
			x++;
		}
		y++;
	}
	draw_minimap_player(&game->frame, game);
	draw_minimap_direction(&game->frame, game);
}

static void	draw_minimap_tile(t_img *img, int map_x, int map_y, int color)
{
	int	screen_x;
	int	screen_y;
	int	i;
	int	j;

	screen_x = (map_x * MM_TILE_SIZE) + MM_OFFSET;
	screen_y = (map_y * MM_TILE_SIZE) + MM_OFFSET;
	i = 0;
	while (i < MM_TILE_SIZE)
	{
		j = 0;
		while (j < MM_TILE_SIZE)
		{
			put_pixel_transparant(img, screen_x + j, screen_y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_player(t_img *img, t_game *game)
{
	int	p_screen_x;
	int	p_screen_y;
	int	i;
	int	j;

	p_screen_x = (int)(game->player.pos_x * MM_TILE_SIZE) + MM_OFFSET;
	p_screen_y = (int)(game->player.pos_y * MM_TILE_SIZE) + MM_OFFSET;
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel(img, p_screen_x + j, p_screen_y + i, MM_COLOR_PLAYER);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_direction(t_img *img, t_game *game)
{
	int		p_screen_x;
	int		p_screen_y;
	int		dir_line_x;
	int		dir_line_y;
	float	t;

	p_screen_x = (int)(game->player.pos_x * MM_TILE_SIZE) + MM_OFFSET;
	p_screen_y = (int)(game->player.pos_y * MM_TILE_SIZE) + MM_OFFSET;
	t = 0.0;
	while (t < 8.0)
	{
		dir_line_x = (int)roundf(p_screen_x + game->player.dir_x * t);
		dir_line_y = (int)roundf(p_screen_y + game->player.dir_y * t);
		put_pixel(img, dir_line_x, dir_line_y, MM_COLOR_DIR);
		t += 0.5f;
	}
}
