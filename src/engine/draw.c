/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:04:19 by cris              #+#    #+#             */
/*   Updated: 2026/05/21 20:23:24 by cris             ###   ########.fr       */
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
