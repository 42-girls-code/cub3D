/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:21:29 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 12:28:31 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// static void	init_checker(int *checker, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		checker[i] = 0;
// 		i++;
// 	}
// }

// static void	init_map(t_map *map)
// {
// 	map->rows = 0;
// 	map->cols = 0;
// 	// map->head = NULL;
// 	map->grid = NULL;
// 	// init_checker(map->checker, 256);
// }

// void	read_map(int fd, t_game *game)
// {
// 	char	*line;

// 	init_t_config(&game->config);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (!is_empty_line(line))
// 			process_map_line(line, game);
// 		free(line);
// 		line = get_next_line;
// 	}
// 	return (0);
// }

// int	process_map_line(char *line, t_game *game)
// {
// 	char	**split_line;

// 	split_line = ft_split(line, ' ');
// 	if (!split_line)
// 		return (message_erro("Error: invalid line."));
// 	if (ft_strcmp(split_line[0], "NO") == 0
// 		|| ft_strcmp(split_line[0], "SO") == 0
// 		|| ft_strcmp(split_line[0], "WE") == 0
// 		|| ft_strcmp(split_line[0], "EA") == 0)
// 		set_dir_config(split_line[0], split_line[1], game);
// 	else if (ft_strcmp(split_line[0], "F") == 0
// 			|| ft_strcmp(split_line[0], "C") == 0)
// 			set_color_config(split_line[0], split_line[1], game);
// 	else
// 		parser_map(line, game);
// 	free_array(split_line);
// 	return (0);
// }

// int	set_dir_config(char	*type, char	*path, t_game *game)
// {
// 	char	**target;

// 	if (ft_strcmp(type, "NO") == 0)
// 		target = &game->config.no;
// 	else if (ft_strcmp(type, "SO") == 0)
// 		target = &game->config.so;
// 	else if (ft_strcmp(type, "WE") == 0)
// 		target = &game->config.we;
// 	else if (ft_strcmp(type, "EA") == 0)
// 		target = &game->config.ea;
// 	if (*target != NULL)
// 		return (message_erro("Error: duplicate configuration."));
// 	*target = ft_strdup(path);
// 	return (0);
// }

// int	set_color_config(char	*type, char	*rgb, t_game *game)
// {
// 	if (ft_strcmp(type, "F") == 0)
// 	{
// 		if (game->config.floor_color != -1)
// 			return (message_erro("Error: duplicate configuration."));
// 		game->config.floor_color = rgb;
// 	}
// 	else if (ft_strcmp(type, "C") == 0)
// 	{
// 		if (game->config.ceiling_color != -1)
// 			return (message_erro("Error: duplicate configuration."));
// 		game->config.ceiling_color = rgb;
// 	}
// 	return (0);
// }
