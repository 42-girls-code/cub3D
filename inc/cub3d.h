/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:20:33 by ingrid            #+#    #+#             */
/*   Updated: 2026/06/11 02:26:53 by cris_sky         ###   ########.fr       */
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
# define ENTER_MAIN 65293
# define ENTER_NUMPAD 65421
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define MOVE_SPEED 0.03
# define ROT_SPEED 0.02
# define PLAYER_RADIUS 0.3
# define MOUSE_SENSITIVITY 0.02

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	int		tex_x;
	int		tex_num;
}	t_ray;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

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
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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
	t_img			textures[4];
	t_keys			keys;
	int				mouse_x;
	double			mouse_delta;
}	t_game;

typedef struct s_draw
{
	int		draw_start;
	int		draw_end;
	double	step;
	double	tex_pos;
}	t_draw;

//utils.c
int		message_erro(char *message);
int		is_space(char c);
void	free_array(char **arr);
int		free_array_erro(char **ptr);
void	exit_error(t_game *game, char *specific_msg);

//cleanup.c
void	clean_up(t_game *game);

//engine/mlx_init.c
void	init_mlx(t_game *game);
void	load_intro(t_game *game);

//engine/hooks.c
int		handle_close(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
void	update_player_position(t_game *game);

//engine/render.c
void	render_background(t_game *game);
int		render_game(t_game *game);

//engine/image.c
void	create_image(t_game *game);

//engine/draw.c
void	put_pixel(t_img *img, int x, int y, int color);

//player/move.c
void	move_player_forward_back(t_game *game, double speed);
void	move_player_sideways(t_game *game, double speed);

//player/rotate.c
void	rotate_player(t_game *game, double angle);

//engine/texture.c
int		load_game_texture(t_game *game);

//engine/minimap.c
void	draw_minimap(t_game *game);
void	put_pixel_transparant(t_img *img, int x, int y, int color);

//engine/raycasting_utils.c
void	get_tex_info(t_game *game, t_ray *ray);
void	draw_column(t_game *game, t_ray *ray, int x);

//engine/raycasting.c
void	raycasting(t_game *game);

int		handle_mouse_move(int x, int y, t_game *game);

#endif
