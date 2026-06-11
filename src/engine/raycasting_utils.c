/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 02:14:29 by cris_sky          #+#    #+#             */
/*   Updated: 2026/06/11 02:35:09 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <math.h>

static void	set_tex_x(t_game *game, t_ray *ray, double wall_x)
{
	ray->tex_x = (int)(wall_x * game->textures[ray->tex_num].width);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
}

void	get_tex_info(t_game *game, t_ray *ray)
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
	set_tex_x(game, ray, wall_x);
}

static void	init_draw(t_ray *ray, t_draw *d, int tex_height)
{
	int	line_height;

	line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	d->draw_start = (SCREEN_HEIGHT - line_height) / 2;
	d->draw_end = (SCREEN_HEIGHT + line_height) / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	if (d->draw_end >= SCREEN_HEIGHT)
		d->draw_end = SCREEN_HEIGHT - 1;
	d->step = (double)tex_height / line_height;
	d->tex_pos = (d->draw_start - (SCREEN_HEIGHT - line_height) / 2.0)
		* d->step;
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_draw	d;
	t_img	*tex;
	int		color;
	int		y;

	tex = &game->textures[ray->tex_num];
	init_draw(ray, &d, tex->height);
	y = d.draw_start;
	while (y <= d.draw_end)
	{
		color = *(int *)(tex->addr
				+ ((int)d.tex_pos & (tex->height - 1)) * tex->line_len
				+ ray->tex_x * (tex->bpp / 8));
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		put_pixel(&game->frame, x, y, color);
		d.tex_pos += d.step;
		y++;
	}
}
