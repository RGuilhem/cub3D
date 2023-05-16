/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:35:59 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 10:53:27 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>
#include <math.h>

void	setup_dir(t_vec2f *dir, t_player *player, int keycode)
{
	static t_mat2x2	rot_left;
	static t_mat2x2	rot_right;
	static int		is_setup;

	if (!is_setup)
	{
		is_setup = 1;
		rot_left = (t_mat2x2){cos(ROT_90), -sin(ROT_90),
			sin(ROT_90), cos(ROT_90)};
		rot_right = (t_mat2x2){cos(-ROT_90), -sin(-ROT_90),
			sin(-ROT_90), cos(-ROT_90)};
	}
	*dir = (t_vec2f){.x = player->dir.x, .y = player->dir.y};
	if (keycode == KEY_A)
		rotate_vec2f(dir, &rot_right);
	else if (keycode == KEY_D)
		rotate_vec2f(dir, &rot_left);
}

static int	can_move(t_map *map, t_player *player, t_vec2f *move)
{
	t_vec2i	new_pos;

	new_pos.x = (int)(player->pos.x + move->x);
	new_pos.y = (int)(player->pos.y + move->y);
	if (map->grid[new_pos.y][new_pos.x] == WALL)
		return (0);
	return (1);
}

void	move_player(t_map *map, t_player *player, int keycode)
{
	t_vec2f	move;
	t_vec2f	dir;

	setup_dir(&dir, player, keycode);
	if (keycode == KEY_W)
		move = (t_vec2f){.x = player->dir.x * MOVE_SIZE,
			.y = player->dir.y * MOVE_SIZE};
	else if (keycode == KEY_S)
		move = (t_vec2f){.x = -player->dir.x * MOVE_SIZE,
			.y = -player->dir.y * MOVE_SIZE};
	else if (keycode == KEY_A)
		move = (t_vec2f){.x = dir.x * MOVE_SIZE,
			.y = dir.y * MOVE_SIZE};
	else if (keycode == KEY_D)
		move = (t_vec2f){.x = dir.x * MOVE_SIZE,
			.y = dir.y * MOVE_SIZE};
	if (can_move(map, player, &move))
	{
		player->pos.x += move.x;
		player->pos.y += move.y;
	}
	player->pos_map.x = (int) player->pos.x;
	player->pos_map.y = (int) player->pos.y;
}
