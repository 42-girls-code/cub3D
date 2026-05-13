/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:33:32 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 12:33:35 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef struct s_game t_game;

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
int	set_color(char *line, t_type type, t_game *game);

//parse_map.c
int	parse_map_file(char *path, t_game *game);

//parse_texture.c
int	set_texture(char *line, t_type type, t_game *game);

//valid_map.c
int	valid_cub_extension(char *path);

//map_read.c
// void	read_map(int fd, t_game *game);

//map_utils.c
// int		is_c_valid(char c);

#endif
