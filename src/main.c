/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:19:55 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 09:31:59 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	init_t_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->config.floor_color = -1;
	game->config.ceiling_color = -1;
	game->config.count = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (message_erro("Error: no map file provided."));
	init_t_game(&game);
	if (parse_map_file(argv[1], &game))
		return (1);
	return (0);
}
