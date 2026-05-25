/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:21:29 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/25 15:19:33 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

static t_type	get_line_type(char *line);
static int		is_line_empty(char *line);
static int		is_map_line_valid(char *line, t_game *game);

int	process_config(char *line, t_game *game)
{
	t_type	type;

	type = get_line_type(line);
	if (type == SKIP)
		return (0);
	if (type == NONE && game->config.count < 6)
		return (message_erro("Error: Incomplete configuration or invalid."));
	if (type == NONE)
		return (message_erro("Error: Invalid id or Map before configs."));
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

int	process_map_line(char *line, t_game *game)
{
	t_list	*new_node;
	char	*content;

	if (game->map_list == NULL && is_line_empty(line))
		return (0);
	if (game->map_list != NULL && is_line_empty(line))
		return (message_erro("Error: Empty line inside/after map"));
	if (!is_map_line_valid(line, game))
		return (1);
	content = ft_strtrim(line, "\n");
	if (!content)
		return (1);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return (1);
	}
	ft_lstadd_back(&game->map_list, new_node);
	return (0);
}

static int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	return (0);
}

static int	is_map_line_valid(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr("NSEW", line[i]))
			save_player_info(game, line[i], i);
		if (game->player_count > 1)
		{
			ft_putendl_fd("Error: multiple players detected.", 2);
			return (0);
		}
		if (ft_strchr("01NSEW ", line[i]) == NULL)
		{
			ft_putendl_fd("Error: map contains an invalid character.", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
