/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:34:17 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 16:31:51 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <math.h>

void	handle_mice(t_gui *gui, t_map *map)
{
	int			x;
	int			y;

	mlx_mouse_get_pos(gui->mlx_win, &x, &y);
	if (x < WIN_W / 2)
		rotate_player(&map->player, L_ARROW, 2);
	else if (x > WIN_W / 2)
		rotate_player(&map->player, R_ARROW, 2);
	mlx_mouse_move(gui->mlx_win, WIN_W / 2, WIN_H / 2);
	mlx_mouse_hide();
}
