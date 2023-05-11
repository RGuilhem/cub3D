/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:58:35 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 16:19:09 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"

void	setup_background(t_gui *gui, t_map *map)
{
	int	x;
	int	y;

	(void) map;
	y = -1;
	while (++y < WIN_H / 2)
	{
		x = -1;
		while (++x < WIN_W)
			put_pixel(&gui->background, x, y, 0x0077B5FE);
	}
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			put_pixel(&gui->background, x, y, 0x0070726E);
	}
	mlx_put_image_to_window(gui->mlx, gui->mlx_win, gui->background.img, 0, 0);
}
