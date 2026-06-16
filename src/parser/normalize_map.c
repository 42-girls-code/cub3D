/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:19:37 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/25 14:43:22 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dimensions_map(t_game *game);
static int	normalize_map(t_game *game);
static char	*fill_line_nomalize(char *line_content, int width);

int	convert_list_to_array(t_game *game)
{
	set_dimensions_map(game);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (1);
	if (normalize_map(game) != 0)
		return (1);
	return (0);
}

static void	set_dimensions_map(t_game *game)
{
	int		width;
	int		aux;
	t_list	*tmp;

	game->map.height = ft_lstsize(game->map_list);
	tmp = game->map_list;
	aux = 0;
	width = 0;
	while (tmp)
	{
		aux = ft_strlen(tmp->content);
		if (aux > width)
			width = aux;
		tmp = tmp->next;
	}
	game->map.width = width;
}

static int	normalize_map(t_game *game)
{
	t_list	*tmp;
	int		i;

	tmp = game->map_list;
	i = 0;
	while (tmp)
	{
		game->map.grid[i] = fill_line_nomalize(tmp->content, game->map.width);
		if (!game->map.grid[i])
		{
			while (--i >= 0)
				free(game->map.grid[i]);
			free(game->map.grid);
			game->map.grid = NULL;
			return (1);
		}
		tmp = tmp->next;
		i++;
	}
	game->map.grid[i] = NULL;
	return (0);
}

static char	*fill_line_nomalize(char *line_content, int width)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (width + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (line_content[i])
	{
		new_str[i] = line_content[i];
		i++;
	}
	while (i < width)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
