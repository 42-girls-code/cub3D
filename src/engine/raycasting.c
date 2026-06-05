/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:07:06 by cris              #+#    #+#             */
/*   Updated: 2026/06/05 17:34:50 by cris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <math.h>

static void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->dir_y);
}

static void	init_step(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) * ray->delta_dist_y;
	}
}

static void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	calc_wall_dist(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2.0) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2.0) / ray->dir_y;
}


static void	get_tex_info(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0 && ray->step_x > 0)
		ray->tex_num = EAST;
	else if (ray->side == 0 && ray->step_x < 0)
		ray->tex_num = WEST;
	else if (ray->side == 1 && ray->step_y > 0)
		ray->tex_num = SOUTH;
	else
		ray->tex_num = NORTH;
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * game->textures[ray->tex_num].width);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
}

static void	draw_column(t_game *game, t_ray *ray, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	t_img	*tex;

	line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	draw_start = (SCREEN_HEIGHT - line_height) / 2;
	draw_end = (SCREEN_HEIGHT + line_height) / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	tex = &game->textures[ray->tex_num];
	step = (double)tex->height / line_height;
	tex_pos = (draw_start - (SCREEN_HEIGHT - line_height) / 2.0) * step;
	y = draw_start;
	while (y <= draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		color = *(int *)(tex->addr + tex_y * tex->line_len
				+ ray->tex_x * (tex->bpp / 8));
		if (ray->side == 1)
    		color = (color >> 1) & 0x7F7F7F;
		put_pixel(&game->frame, x, y, color);
		y++;
	}
}

void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(game, &ray, x);
		init_step(game, &ray);
		perform_dda(game, &ray);
		calc_wall_dist(game, &ray);
		get_tex_info(game, &ray);
		draw_column(game, &ray, x);
		x++;
	}
}
