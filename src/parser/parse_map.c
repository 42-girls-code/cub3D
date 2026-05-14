/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:51:43 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/14 18:09:24 by ilemos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

static int		handle_line(char *line, t_game *game, t_state *state);
static int		handle_parse_error(int fd);
static int		validate_final_config(t_game *game);
static int		convert_list_to_array(t_game *game);

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
	if (validate_final_config(game))
		return (1);
	if (convert_list_to_array(game))
		return (1);
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
	{
		if (process_map_line(line, game) != 0)
			return (1);
	}
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

static int	validate_final_config(t_game *game)
{
	if (game->config.count < 6)
		return (message_erro("Error: Incomplete config."));
	if (game->player_count == 0)
		return (message_erro("Error: No player starting position."));
	return (0);
}

static int	convert_list_to_array(t_game *game)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = game->map_list;
	game->map.height = ft_lstsize(game->map_list);
	while (tmp)
	{
		while (&tmp->content[i])
			i++;
		if (game->map.width < i)
			game->map.width = i;
		tmp = tmp->next;
	}
	printf("altura: %d \nlargura: %d\n", game->map.height, game->map.width);
	return (0);
}
