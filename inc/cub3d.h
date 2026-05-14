/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:20:33 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/14 10:33:48 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
// # include "parser.h"
// # include "mlx.h"

// # define TILE 68
// # define W 119
// # define S 115
// # define A 97
// # define D 100

// typedef struct s_map
// {
// 	char	**grid;
// 	int		rows;
// 	int		cols;
// 	char	spawn_dir;
// 	// int		checker[256];
// 	double	player_x;
// 	double	player_y;
// 	// t_list	*head;
// }	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	char	dir;
}	t_player;

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_color;
	int		ceiling_color;
	int		count;
}	t_config;

//em construção
typedef struct s_game
{
	t_config	config;
	t_player	player;
	// t_map		map_data;
	t_list		*map_list;
	void		*mlx;
	void		*win;
	int			player_count;
}	t_game;

//map_utils.c
int		is_c_valid(char c);
int		is_line_empty(char *line);
int		is_map_line_valid(char *line, t_game *game);

//utils.c
int		message_erro(char *message);
int		is_space(char c);
void	free_array(char **arr);
int		free_array_erro(char **ptr);
void	exit_error(t_game *game, char *specific_msg);

//cleanup.c
void 	clean_up(t_game *game);

#endif
