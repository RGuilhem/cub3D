/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:36:17 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/16 14:38:32 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>
#include <stdlib.h>

static void	init_deltas(t_dda *dda, t_vec2f *ray)
{
	if (ray->x != 0)
		dda->delta.x = fabs(1 / ray->x);
	else
		dda->delta.x = 0;
	if (ray->y != 0)
		dda->delta.y = fabs(1 / ray->y);
	else
		dda->delta.y = 0;
}

void	init_dda(t_vec2f *ray, t_map *map, t_dda *dda)
{
	t_player	p;

	p = map->player;
	init_deltas(dda, ray);
	if (ray->x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = ((p.pos.x - p.pos_map.x) * dda->delta.x);
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = ((p.pos_map.x + 1 - p.pos.x) * dda->delta.x);
	}
	if (ray->y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = ((p.pos.y - p.pos_map.y) * dda->delta.y);
	}
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = ((p.pos_map.y + 1 - p.pos.y) * dda->delta.y);
	}
}
