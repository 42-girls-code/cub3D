/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:51:43 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 12:46:07 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

static t_type	get_line_type(char *line);
static int		process_config(char *line, t_game *game);

int	parse_map_file(char *path, t_game *game)
{
	int		fd;
	char	*line;
	t_state	state;

	if (valid_cub_extension(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (message_erro("Error: no such file or directory."));
	state = STATE_CONFIG;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (state == STATE_CONFIG)
		{
			if (process_config(line, game) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
			if (game->config.count == 6)
				state = STATE_MAP;
		}
		// else if (state == STATE_MAP)
		// 	process_map_line(line, game); // implementar
		free(line);
	}
	close(fd);
	return (0);
}

static int	process_config(char *line, t_game *game)
{
	t_type	type;

	type = get_line_type(line);
	if (type == SKIP)
		return (0);
	if (type == NONE)
		return (message_erro("Error: Invalid identifier or unexpected line."));
	if (type >= NORTH && type <= EAST)
	{
		if (set_texture(line, type, game) != 0)
			return (1);
		game->config.count++;
		return (0);
	}
	if (type == FLOOR || type == CEILING)
	{
		if (set_color(line, type, game) != 0)
			return (1);
		game->config.count++;
		return (0);
	}
	return (1);
}

static t_type	get_line_type(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (SKIP);
	if (ft_strncmp(line + i, "NO ", 3) == 0)
		return (NORTH);
	if (ft_strncmp(line + i, "SO ", 3) == 0)
		return (SOUTH);
	if (ft_strncmp(line + i, "WE ", 3) == 0)
		return (WEST);
	if (ft_strncmp(line + i, "EA ", 3) == 0)
		return (EAST);
	if (ft_strncmp(line + i, "F ", 2) == 0)
		return (FLOOR);
	if (ft_strncmp(line + i, "C ", 2) == 0)
		return (CEILING);
	return (NONE);
}
