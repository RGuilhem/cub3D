/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:06:34 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 17:15:58 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define EMPTY '0'
# define WALL '1'

# define WIN_W 1280
# define WIN_H 720

# define TEX_S 64
# define FOV 1.0472
# define NB_RAYS 60

typedef struct s_frame
{
	void	*img;
	char	*address;
	int		bpp;
	int		ll;
	int		endian;
}				t_frame;

enum e_map_dir
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}			t_color;

typedef struct s_vec2f
{
	double	x;
	double	y;
}			t_vec2f;

typedef struct s_vec2i
{
	int	x;
	int	y;
}			t_vec2i;

typedef struct s_mat2x2
{
	double	elem1_1;
	double	elem1_2;
	double	elem2_1;
	double	elem2_2;
}			t_mat2x2;

typedef struct s_player
{
	t_vec2f		pos;	 // (5 * 32, 7 * 32)
	t_vec2i		pos_map; // (5, 7)
	t_vec2f		dir;
	t_mat2x2	m_rotations[NB_RAYS];
	t_vec2f		rays[NB_RAYS]; //TODO change to something smaller?
}			t_player;

typedef struct s_map
{
	t_color		f_color;
	t_color		c_color;
	t_frame		textures[4];
	t_player	player;
	t_vec2i		size;
	char		**grid;
}			t_map;

# define MAX_KEYS 6
# define KEY_EMPTY -1
# define L_ARROW 123
# define R_ARROW 124
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ROT_ANG -0.0523599
# define ROT_90 1.5708
# define MOVE_SIZE 2

typedef struct s_gui
{
	void	*mlx;
	void	*mlx_win;
	t_frame	screen;
	t_frame	background;
	int		keys_pressed[MAX_KEYS];
}			t_gui;

typedef struct s_data
{
	t_gui	*gui;
	t_map	*map;
}			t_data;

int		map_load(t_map *map, char *map_path);
void	read_lines(const char *path, char ***lines);
int		parse_colors(t_map *map, char **lines);
int		parse_textures(t_map *map, char **lines);
int		parse_map(t_map *map, char **lines);

void	setup_events(t_gui *gui);
void	apply_events(t_data *data);
void	init_keys_list(t_gui *gui);
int		reg_keyup(int keycode, t_gui *gui);
int		reg_keydown(int keycode, t_gui *gui);
void	move_player(t_player *player, int keycode);
void	rotate_player(t_player *player, int keycode);
void	rotate_vec2f(t_vec2f *vec, t_mat2x2 *mat);

void	put_pixel(t_frame *fra, int x, int y, int color);
void	draw_line(t_frame *frame, t_vec2f *a, t_vec2f *b);
void	setup_background(t_gui *gui, t_map *map);

void	define_angle_of_rays(t_map *map);
void	create_rays(t_map *map);
void	draw_rays(t_gui *gui, t_map *map);

#endif
