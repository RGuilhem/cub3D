/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:40:06 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 15:42:28 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>

static void	init_matrices(t_mat2x2 *rot_left, t_mat2x2 *rot_right)
{
	*rot_left = (t_mat2x2){cos(ROT_ANG), -sin(ROT_ANG),
		sin(ROT_ANG), cos(ROT_ANG)};
	*rot_right = (t_mat2x2){cos(-ROT_ANG), -sin(-ROT_ANG),
		sin(-ROT_ANG), cos(-ROT_ANG)};
}

void	rotate_player(t_player *player, int dir)
{
	static t_mat2x2	rot_left;
	static t_mat2x2	rot_right;
	static int		is_setup;

	if (!is_setup)
	{
		is_setup = 1;
		init_matrices(&rot_left, &rot_right);
	}
	if (dir == L_ARROW)
		rotate_vec2f(&player->dir, &rot_left);
	else if (dir == R_ARROW)
		rotate_vec2f(&player->dir, &rot_right);
}
