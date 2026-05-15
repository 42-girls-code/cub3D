/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:16:16 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 12:23:27 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static char	*get_value_after_id(char *line);
static int	parse_rgb_to_int(char *rgb_str);
static int	is_str_digit(char *str);

int	set_color(char *line, t_type type, t_game *game)
{
	char	*rgb_str;
	int		*target;
	int		result;

	if (type == FLOOR)
		target = &game->config.floor_color;
	else
		target = &game->config.ceiling_color;
	if (*target != -1)
		return (message_erro("Error: Duplicate color."));
	rgb_str = get_value_after_id(line);
	result = parse_rgb_to_int(rgb_str);
	free(rgb_str);
	if (result == -1)
		return (message_erro("Error: Invalid RGB values"));
	*target = result;
	return (0);
}

static char	*get_value_after_id(char *line)
{
	int		start;
	int		len;
	char	*path;

	start = 0;
	while (line[start] && is_space(line[start]))
		start++;
	while (line[start] && !is_space(line[start]))
		start++;
	while (line[start] && is_space(line[start]))
		start++;
	len = start;
	while (line[len] && line[len] != '\n')
		len++;
	path = ft_substr(line, start, len - start);
	return (path);
}

static int	parse_rgb_to_int(char *rgb_str)
{
	char	**rgb;
	int		colors[3];
	int		i;
	int		final_color;

	rgb = ft_split(rgb_str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (free_array_erro(rgb));
	i = 0;
	while (i < 3)
	{
		if (!is_str_digit(rgb[i]))
			return (free_array_erro(rgb));
		colors[i] = ft_atoi(rgb[i]);
		if (colors[i] < 0 || colors[i] > 255)
			return (free_array_erro(rgb));
		i++;
	}
	free_array(rgb);
	final_color = (colors[0] << 16 | colors[1] << 8 | colors[2]);
	return (final_color);
}

static int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (!str[i] || str[i] == '\n')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}
