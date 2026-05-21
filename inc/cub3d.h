/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:20:33 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/20 16:42:14 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define ENTER 65421
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

typedef enum e_game_state
{
	STATE_INTRO,
	STATE_PLAYING,
	STATE_GAMEOVER
}	t_game_state;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

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

typedef struct s_game
{
	t_config		config;
	t_player		player;
	t_map			map;
	t_list			*map_list;
	int				player_count;
	void			*mlx;
	void			*win;
	t_game_state	state;
	t_img			intro;
	t_img			frame;
}	t_game;

//map_utils.c
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

//engine/mlx_init.c
void	init_mlx(t_game *game);
void	load_intro(t_game *game);

//engine/hooks.c
int		handle_close(t_game *game);
int		handle_keypress(int keycode, t_game *g);

//engine/render.c
int		render_game(t_game *game);

#endif
