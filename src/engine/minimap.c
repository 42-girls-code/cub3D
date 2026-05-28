/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 08:31:53 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/28 09:59:24 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define MM_TILE_SIZE 10
# define MM_COLOR_WALL 0x343A40
# define MM_COLOR_FLOOR 0x000000
# define MM_COLOR_PLAYER 0x00F5D4
# define MM_COLOR_DIR 0x00BBF9
# define MM_COLOR_BORDER 0xD4AF37
# define MM_OFFSET 20
// # define MM_COLOR_DIR 0x0000FF

static void	draw_minimap_tile(t_img *img, int map_x, int map_y, int color);
static void	draw_minimap_player(t_img *img, t_game *game);
static void	draw_minimap_direction(t_img *img, t_game *game);
// static void	draw_minimap_border(t_img *img, t_game *game);
// static void	draw_minimap_tile_transp(t_img *img, int map_x, int map_y, int color);

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
	// draw_minimap_border(&game->frame, game); // a finalizar
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
			put_pixel(img, screen_x + j, screen_y + i, color);
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

	p_screen_x = (game->player.pos_x * MM_TILE_SIZE) + MM_OFFSET;
	p_screen_y = (game->player.pos_y * MM_TILE_SIZE) + MM_OFFSET;
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

	p_screen_x = (game->player.pos_x * MM_TILE_SIZE) + MM_OFFSET;
	p_screen_y = (game->player.pos_y * MM_TILE_SIZE) + MM_OFFSET;
	t = 0;
	while (t < 8.0)
	{
		dir_line_x = p_screen_x + (game->player.dir_x * t);
		dir_line_y = p_screen_y + (game->player.dir_y * t);
		put_pixel(img, dir_line_x, dir_line_y, MM_COLOR_DIR);
		t += 0.5;
	}
}

void	put_pixel_transparant(t_img *img, int x, int y, int color)
{
	int	offset;
	int	current_color;
	int	mixed_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = y * img->line_len + x * (img->bpp / 8);
	current_color = *(unsigned int *)(img->addr + offset);
	mixed_color = ((current_color & 0xFEFEFE) >> 1) + ((color & 0xFEFEFE) >> 1);
	*(unsigned int *)(img->addr + offset) = mixed_color;
}

// static void	draw_minimap_tile_transp(t_img *img, int map_x, int map_y, int color)
// {
// 	int	screen_x;
// 	int	screen_y;
// 	int	i;
// 	int	j;

// 	screen_x = (map_x * MM_TILE_SIZE) + MM_OFFSET;
// 	screen_y = (map_y * MM_TILE_SIZE) + MM_OFFSET;
// 	i = 0;
// 	while (i < MM_TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < MM_TILE_SIZE)
// 		{
// 			put_pixel_transparant(img, screen_x + j, screen_y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	draw_minimap_border(t_img *img, t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	max_width;
// 	int	max_height;

// 	y = 0;
// 	max_width = 0;
// 	while (game->map.grid[y])
// 	{
// 		x = 0;
// 		while (game->map.grid[y][x])
// 			x++;
// 		if (x > max_width)
// 			max_width = x;
// 		y++;
// 	}
// 	max_height = y;
// 	put_pixel(img, max_width, max_height, MM_COLOR_BORDER);
// }
