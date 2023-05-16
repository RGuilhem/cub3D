/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:18:13 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 14:40:36 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_dda	cast_one_ray(t_vec2f *ray, t_map *map, int done)
{
	t_dda	dda;

	dda = (t_dda){.pos.x = map->player.pos_map.x,
		.pos.y = map->player.pos_map.y};
	init_dda(ray, map, &dda);
	while (!done)
	{
		if ((dda.side_dist.x < dda.side_dist.y && dda.side_dist.x != 0)
			|| dda.side_dist.y == 0)
		{
			dda.side_dist.x += dda.delta.x;
			dda.pos.x += dda.step.x;
			dda.horizontal_hit = 0;
		}
		else
		{
			dda.side_dist.y += dda.delta.y;
			dda.pos.y += dda.step.y;
			dda.horizontal_hit = 1;
		}
		if (map->grid[dda.pos.y][dda.pos.x] == WALL)
			done = 1;
	}
	return (dda);
}

void	cast_rays(t_gui *gui, t_map *map)
{
	int		i;
	int		done;
	t_dda	dda;

	i = -1;
	done = 0;
	while (++i < NB_RAYS)
	{
		dda = cast_one_ray(&map->player.rays[i], map, done);
		if (dda.horizontal_hit)
			dda.dist = dda.side_dist.y - dda.delta.y;
		else
			dda.dist = dda.side_dist.x - dda.delta.x;
		dda.start = -(WIN_H / dda.dist) / 2 + WIN_H / 2;
		if (dda.start < 0)
			dda.start = 0;
		dda.end = (WIN_H / dda.dist) / 2 + WIN_H / 2;
		if (dda.end >= WIN_H)
			dda.end = WIN_H - 1;
		dda.ray_num = i;
		render_tex_line(&dda, gui, map, &map->player.rays[i]);
	}
}
