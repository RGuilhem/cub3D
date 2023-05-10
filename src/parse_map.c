/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:53:42 by graux             #+#    #+#             */
/*   Updated: 2023/05/10 12:08:57 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"
#include <limits.h>

static int	find_grid_start(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] && lines[i][0] != 'C')
		i++;
	return (i + 1);
}

static void	init_mapgrid(t_map *map, char **lines)
{
	int	max;
	int	i;

	i = -1;
	max = INT_MIN;
	while (lines[++i])
	{
		if (ft_strlen(lines[i]) > max)
			max = ft_strlen(lines[i]);
	}
	map->size.x = max;
	map->size.y = i;
	map->grid = malloc(sizeof(char *) * map->size.y);
	i = -1;
	while (++i < map->size.y)
		map->grid[i] = malloc(sizeof(char) * (map->size.x));
}

int	parse_map(t_map *map, char **lines)
{
	char	**grid;

	grid = &lines[find_grid_start(lines)];
	init_mapgrid(map, grid);
	return (1);
}
