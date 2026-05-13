/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:21:17 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 12:28:56 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	count_split_elements(char **split_line);
static char	**get_target_pointer(t_type type, t_game *game);

int	set_texture(char *line, t_type type, t_game *game)
{
	char	**split_line;
	char	**target;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (1);
	if (count_split_elements(split_line) != 2)
	{
		free_array(split_line);
		return (message_erro("Error: Invalid texture line format."));
	}
	target = get_target_pointer(type, game);
	if (*target != NULL)
	{
		free_array(split_line);
		return (message_erro("Error: Duplicate texture path."));
	}
	*target = ft_strtrim(split_line[1], " \n\r\t\v\f");
	free_array(split_line);
	return (0);
}

static int	count_split_elements(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
		i++;
	return (i);
}

static char	**get_target_pointer(t_type type, t_game *game)
{
	if (type == NORTH)
		return (&game->config.no);
	if (type == SOUTH)
		return (&game->config.so);
	if (type == WEST)
		return (&game->config.we);
	if (type == EAST)
		return (&game->config.ea);
	return (NULL);
}
