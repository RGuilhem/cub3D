/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:01:08 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 14:35:51 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static t_frame	*select_texture(t_dda *dda, t_map *map)
{
	t_frame	*tex;

	tex = NULL;
	if (dda->horizontal_hit && dda->step.y < 0)
		tex = &map->textures[SO];
	else if (dda->horizontal_hit && dda->step.y > 0)
		tex = &map->textures[NO];
	else if (!dda->horizontal_hit && dda->step.x > 0)
		tex = &map->textures[WE];
	else if (!dda->horizontal_hit && dda->step.x < 0)
		tex = &map->textures[EA];
	return (tex);
}

static int	get_color_tex(t_frame *tex, int x, int y)
{
	int		color;
	char	*pix;

	pix = tex->address + (y * tex->ll + x * (tex->bpp / 8));
	color = *(unsigned int *) pix;
	return (color);
}

static void	draw_texture(t_dda *dda, t_gui *gui, t_map *map, int tex_x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	t_frame	*texture;

	texture = select_texture(dda, map);
	step = TEX_S / (WIN_H / dda->dist);
	tex_pos = (dda->start - WIN_H / 2 + (WIN_H / dda->dist) / 2) * step;
	y = dda->start - 1;
	while (++y < dda->end)
	{
		tex_y = (int)tex_pos & ((int)TEX_S - 1);
		put_pixel(&gui->screen, dda->ray_num, y,
			get_color_tex(texture, tex_x, tex_y));
		tex_pos += step;
	}
}

void	render_tex_line(t_dda *dda, t_gui *gui, t_map *map, t_vec2f *ray)
{
	double	x_factor;
	int		x_texture;

	if (!dda->horizontal_hit)
		x_factor = map->player.pos.y + dda->dist * ray->y;
	else
		x_factor = map->player.pos.x + dda->dist * ray->x;
	x_factor -= floor(x_factor);
	x_texture = (int)(x_factor * TEX_S);
	if ((!dda->horizontal_hit && ray->x > 0)
		|| (dda->horizontal_hit && ray->y < 0))
		x_texture = TEX_S - x_texture - 1;
	draw_texture(dda, gui, map, x_texture);
}
