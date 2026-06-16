/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:04:19 by cris              #+#    #+#             */
/*   Updated: 2026/06/11 20:58:29 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= img->width
		|| y < 0 || y >= img->height)
		return ;
	offset = y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)(img->addr + offset) = color;
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
