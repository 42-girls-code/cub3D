/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:33:32 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/26 11:07:17 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef struct s_game	t_game;

typedef enum e_state
{
	STATE_CONFIG,
	STATE_MAP,
	STATE_FINISHED
}	t_state;

typedef enum e_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
	SKIP,
	NONE
}	t_type;

//parse_color.c
int		set_color(char *line, t_type type, t_game *game);

//parse_map.c
int		parse_map_file(char *path, t_game *game);

//parse_texture.c
int		set_texture(char *line, t_type type, t_game *game);

//valid_map.c
int		valid_cub_extension(char *path);
int		validate_map_walls(t_game *game);

//map_config.c
int		process_config(char *line, t_game *game);
int		process_map_line(char *line, t_game *game);

//normalize_map.c
int		convert_list_to_array(t_game *game);

//init_player.c
void	save_player_info(t_game *game, char direction, int x);

#endif
