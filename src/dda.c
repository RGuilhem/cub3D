/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:36:17 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/11 10:05:50 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>
#include <stdlib.h>

void	check_section(t_vec2f *ray, double delta_x, double delta_y, int *i)
{
	delta_x = sqrt(1 + (ray->y * ray->y) / (ray->x * ray->x));
	delta_y = sqrt(1 + (ray->x * ray->x) / (ray->y * ray->y));
}

void	check_step(t_vec2f ray, t_map *map, double delta_x, double delta_y)
{
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;

	if (ray.x < 0)
	{
		step_x = -1;
		side_dist_x = ((map->player.pos.x - map->player.pos_map.x) * delta_x);
	}
	else
	{
		step_x = -1;
		side_dist_x = ((map->player.pos_map.x + 1 - map->player.pos.x) * delta_x);	
	}
	if (ray.y < 0)
	{
		step_y = -1;
		side_dist_y = ((map->player.pos.y - map->player.pos_map.y) * delta_y);
	}
	else
	{
		step_y = 1;
		side_dist_y = ((map->player.pos_map.y + 1 - map->player.pos.y) * delta_y);	
	}
}

void	dda(t_map *map)
{
	double	delta_x;
	double	delta_y;
	int		i;
	t_vec2f	ray;

	i = -1;
	while (++i < NB_RAYS)
	{
		ray = map->player.rays[i];
		check_section(&ray, delta_x, delta_y, &i);
	}
	check_step(ray, map, delta_x, delta_y);
}
