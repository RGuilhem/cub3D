/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:11:41 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 17:19:16 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_rays(t_gui *gui, t_map *map)
{
	t_player	*player;
	int			i;
	t_vec2f		real_dir;

	player = &map->player;
	i = -1;
	while (++i < NB_RAYS)
	{
		real_dir = (t_vec2f){.x = map->player.pos.x + player->rays[i].x * 15,
			.y = map->player.pos.y + player->rays[i].y * 15};
		draw_line(&gui->screen, &map->player.pos, &real_dir);
	}
}
