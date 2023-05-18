/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:06:34 by graux             #+#    #+#             */
/*   Updated: 2023/05/18 10:58:16 by graux            ###   ########.fr       */
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
# define PITCH 100
# define INIT_DIR 1.00001
# define NB_RAYS WIN_W

# define EMPTY_COL 0xFF000000
# define WALL_COL 0x00FF0000
# define PLAYER_COL 0x0000FF00
# define PIX_PER_BLOCK 10

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
	EA,
	END_MAP_DIR
};

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
	t_vec2f		pos;
	t_vec2i		pos_map;
	t_vec2f		dir;
	t_mat2x2	m_rotations[NB_RAYS];
	t_vec2f		rays[NB_RAYS];
}			t_player;

typedef struct s_map
{
	int			tex_setup;
	int			grid_setup;
	int			f_color;
	int			c_color;
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
# define KEY_M 46
# define KEY_ESC 53
# define ROT_ANG -0.0523599
# define ROT_90 1.5708
# define MOVE_SIZE 0.05

typedef struct s_gui
{
	int		minimap_setup;
	void	*mlx;
	void	*mlx_win;
	t_frame	screen;
	t_frame	background;
	t_frame	minimap;
	int		keys_pressed[MAX_KEYS];
}			t_gui;

typedef struct s_data
{
	t_gui	*gui;
	t_map	*map;
}			t_data;

typedef struct s_dda
{
	t_vec2f	delta;
	t_vec2i	step;
	t_vec2f	side_dist;
	t_vec2i	pos;
	int		horizontal_hit;
	int		ray_num;
	double	dist;
	int		start;
	int		end;
}			t_dda;

typedef struct s_hit
{
	t_vec2i	pos;
	int		horizontal_hit;
}			t_hit;

int		map_load(t_gui *gui, t_map *map, char *map_path);
void	read_lines(const char *path, char ***lines);
int		parse_colors(t_map *map, char **lines);
int		parse_textures(t_gui *gui, t_map *map, char **lines);
int		parse_map(t_map *map, char **lines);
int		check_map(t_map *map);

void	setup_events(t_data *data);
void	apply_events(t_data *data);
void	init_keys_list(t_gui *gui);
int		reg_keyup(int keycode, t_gui *gui);
int		reg_keydown(int keycode, t_gui *gui);
void	move_player(t_map *map, t_player *player, int keycode);
void	rotate_player(t_player *player, int dir, int steps);
void	handle_mice(t_gui *gui, t_map *map, int switch_state);
void	rotate_vec2f(t_vec2f *vec, t_mat2x2 *mat);

void	put_pixel(t_frame *fra, int x, int y, int color);
void	setup_background(t_gui *gui, t_map *map);
void	init_minimap(t_gui *gui, t_map *map);

void	define_angle_of_rays(t_map *map);
double	define_lenght_direc(t_vec2f direc_player);
void	create_rays(t_map *map);
void	draw_minimap(t_gui *gui, t_map *map);

void	init_dda(t_vec2f *ray, t_map *map, t_dda *dda);
void	cast_rays(t_gui *gui, t_map *map);
void	render_tex_line(t_dda *dda, t_gui *gui, t_map *map, t_vec2f *ray);

int		free_ppsize(char **tab, int size);
void	cleanup_map(t_gui *gui, t_map *map);
void	cleanup_gui(t_gui *gui);
int		put_error(char *msg);
int		exit_program(t_data *data);

#endif
