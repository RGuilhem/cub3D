/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:02:29 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/16 14:36:35 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>
#include <stdlib.h>

static void	gen_matrix(double a, t_mat2x2 *mat)
{	
	mat->elem1_1 = cos(a);
	mat->elem1_2 = -sin(a);
	mat->elem2_1 = sin(a);
	mat->elem2_2 = cos(a);
}

void	create_rays(t_map *map)
{
	int			i;
	t_player	p;

	i = -1;
	p = map->player;
	while (++i < NB_RAYS)
	{
		map->player.rays[i] = (t_vec2f){.x = p.dir.x * p.m_rotations[i].elem1_1
			+ p.dir.y * p.m_rotations[i].elem1_2, .y = p.dir.x
			* p.m_rotations[i].elem2_1 + p.dir.y * p.m_rotations[i].elem2_2};
	}
}

double	define_lenght_direc(t_vec2f direc_player)
{
	double	res;

	res = sqrt(direc_player.x * direc_player.x
			+ direc_player.y * direc_player.y);
	return (res);
}

void	define_angle_of_rays(t_map *map)
{
	int			i;
	double		opp;
	double		a;

	opp = 2 * (define_lenght_direc(map->player.dir) * 0.60) / NB_RAYS;
	i = -1;
	while (++i < NB_RAYS / 2)
	{
		a = atanl((opp * i) / define_lenght_direc(map->player.dir));
		gen_matrix(a, &map->player.m_rotations[NB_RAYS / 2 + i]);
	}
	i = -1;
	while (++i < NB_RAYS / 2)
	{
		a = -atanl((opp * (NB_RAYS / 2 - i))
				/ define_lenght_direc(map->player.dir));
		gen_matrix(a, &map->player.m_rotations[i]);
	}
}
