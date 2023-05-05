/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:06:34 by graux             #+#    #+#             */
/*   Updated: 2023/05/05 11:54:20 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WIN_W 1280
# define WIN_H 720

typedef struct s_frame
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
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
	float	x;
	float	y;
}			t_vec2f;

typedef struct s_player
{
	t_vec2f	pos;
	t_vec2f	dir;
}			t_player;

typedef struct s_map
{
	t_color		f_color;
	t_color		c_color;
	t_frame		textures[4];
	t_player	player;
}			t_map;

typedef struct s_gui
{
	void	*mlx;
	void	*mlx_win;
}			t_gui;

t_map	*map_load(char *map_path);

#endif
