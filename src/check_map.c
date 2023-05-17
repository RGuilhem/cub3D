/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:11:38 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 11:38:24 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	flood_fill(char **tab, t_vec2i pos, char fill[2], t_vec2i size)
{
	t_vec2i	n_pos;

	if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y
		|| tab[pos.y][pos.x] != fill[0])
		return ;
	tab[pos.y][pos.x] = fill[1];
	n_pos = (t_vec2i){pos.x + 1, pos.y};
	flood_fill(tab, n_pos, fill, size);
	n_pos = (t_vec2i){pos.x - 1, pos.y};
	flood_fill(tab, n_pos, fill, size);
	n_pos = (t_vec2i){pos.x, pos.y + 1};
	flood_fill(tab, n_pos, fill, size);
	n_pos = (t_vec2i){pos.x, pos.y - 1};
	flood_fill(tab, n_pos, fill, size);
}

int	check_map(t_map *map)
{
	t_vec2i	size;
	t_vec2i	start;
	char	fill[2];

	size = map->size;
	start = (t_vec2i){0, 0};
	fill[0] = '0';
	fill[1] = '2';
	flood_fill(map->grid, start, fill, size);
	start = (t_vec2i){map->player.pos_map.x, map->player.pos_map.y};
	fill[0] = '2';
	fill[1] = '3';
	flood_fill(map->grid, start, fill, size);
	if (map->grid[0][0] == '3')
		return (0);
	return (1);
}
