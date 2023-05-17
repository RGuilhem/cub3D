/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:49:21 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 13:59:52 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"

static void	draw_map_block(t_gui *gui, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PIX_PER_BLOCK)
	{
		j = -1;
		while (++j < PIX_PER_BLOCK)
			put_pixel(&gui->minimap, x + j, y + i, color);
	}
}

void	draw_minimap(t_gui *gui, t_map *map)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
		{
			if (map->grid[y][x] == WALL)
				color = WALL_COL;
			else
				color = EMPTY_COL;
			draw_map_block(gui, x * PIX_PER_BLOCK, y * PIX_PER_BLOCK, color);
		}
	}
	y = map->player.pos_map.y;
	x = map->player.pos_map.x;
	draw_map_block(gui, x * PIX_PER_BLOCK, y * PIX_PER_BLOCK, PLAYER_COL);
	mlx_put_image_to_window(gui->mlx, gui->mlx_win, gui->minimap.img, 0, 0);
}

void	init_minimap(t_gui *gui, t_map *map)
{
	gui->minimap_setup = 1;
	gui->minimap.img = mlx_new_image(gui->mlx, map->size.x * PIX_PER_BLOCK,
			map->size.y * PIX_PER_BLOCK);
	gui->minimap.address = mlx_get_data_addr(gui->minimap.img,
			&gui->minimap.bpp, &gui->minimap.ll, &gui->minimap.endian);
}
