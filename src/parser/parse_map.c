/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:51:43 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 19:08:40 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

static int		handle_line(char *line, t_game *game, t_state *state);
static int		handle_parse_error(int fd);

int	parse_map_file(char *path, t_game *game)
{
	int		fd;
	char	*line;
	t_state	state;

	if (valid_cub_extension(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (message_erro("Error: No such file or directory."));
	state = STATE_CONFIG;
	line = get_next_line(fd);
	while (line)
	{
		if (handle_line(line, game, &state))
		{
			free(line);
			return (handle_parse_error(fd));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->config.count < 6)
		return (message_erro("Error: Incomplete config."));
	return (0);
}

static int	handle_line(char *line, t_game *game, t_state *state)
{
	if (*state == STATE_CONFIG)
	{
		if (process_config(line, game) != 0)
			return (1);
		if (game->config.count == 6)
			*state = STATE_MAP;
	}
	else if (*state == STATE_MAP)
		process_map_line(line, game);
	return (0);
}

static int	handle_parse_error(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
