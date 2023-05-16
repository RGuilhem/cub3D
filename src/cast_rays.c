/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:18:13 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 11:31:18 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>

static t_dda	cast_one_ray(t_vec2f *ray, t_map *map)
{
	t_dda	dda;
	int		done;
	int		test_counter;

	test_counter = 0;
	done = 0;
	dda = (t_dda){.pos.x = map->player.pos_map.x,
		.pos.y = map->player.pos_map.y};
	init_dda(ray, map, &dda);
	while (!done)
	{
		if ((dda.side_dist.x < dda.side_dist.y && dda.side_dist.x != 0) || dda.side_dist.y == 0)
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
		test_counter++;
		if (map->grid[dda.pos.y][dda.pos.x] == WALL)
			done = 1;
	}
	return (dda);
}

void	cast_rays(t_gui *gui, t_map *map)
{
	int		i;
	t_dda	dda;
	double	dist;
	t_vec2f	start;
	t_vec2f	end;
	static	int	yessay;

	i = -1;
	while (++i < NB_RAYS)
	{
		dda = cast_one_ray(&map->player.rays[i], map);
		if (dda.horizontal_hit)
			dist = dda.side_dist.y - dda.delta.y;
		else
			dist = dda.side_dist.x - dda.delta.x;
		//dist = define_lenght_direc(dda.side_dist);
		if (i == WIN_W / 2 && yessay++ % 60 == 0)
		{
			printf("ray: %f %f\n", map->player.rays[i].x, map->player.rays[i].y);
			printf("dist hit: %f\n", dist);
			printf("hit:     %d %d\n", dda.pos.x, dda.pos.y);
		}
		start = (t_vec2f){.x = i, .y = -(WIN_H / dist) / 2 + WIN_H / 2};
		end = (t_vec2f){.x = i, .y = (WIN_H / dist) / 2 + WIN_H / 2};
		if (dda.horizontal_hit)
			draw_line(&gui->screen, &start, &end, 0x00FF0000);
		else
			draw_line(&gui->screen, &start, &end, 0x00DF0000);
	}
}
