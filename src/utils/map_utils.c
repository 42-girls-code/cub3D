/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:40:27 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/14 10:47:01 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	return (0);
}

static void	save_player_info(t_game *game, char direction, int x)
{
	game->player.pos_y = (double)ft_lstsize(game->map_list);
	game->player.pos_x = (double)x;
	game->player.dir = direction;
	game->player_count++;
}

int	is_map_line_valid(char *line, t_game *game)
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
