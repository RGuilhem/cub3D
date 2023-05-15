/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:53:42 by graux             #+#    #+#             */
/*   Updated: 2023/05/15 16:33:01 by graux            ###   ########.fr       */
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
	size_t	max;
	int		i;

	i = -1;
	max = 0;
	while (lines[++i])
	{
		if (ft_strlen(lines[i]) > max)
			max = ft_strlen(lines[i]);
	}
	map->size = (t_vec2i){.x = max, .y = i};
	map->grid = malloc(sizeof(char *) * map->size.y);
	i = -1;
	while (++i < map->size.y)
		map->grid[i] = malloc(sizeof(char) * (map->size.x));
}

static int	add_map_elem(t_map *map, char **grid, int i, int j)
{
	static int	player_set;
	char		c;

	c = grid[i][j];
	if (c == EMPTY || c == ' ')
		map->grid[i][j] = EMPTY;
	else if (c == WALL)
		map->grid[i][j] = WALL;
	else if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && !player_set)
	{
		map->grid[i][j] = EMPTY;
		map->player.pos_map = (t_vec2i){.x = j, .y = i};
		map->player.pos = (t_vec2f){.x = (j - 0.5),
			.y = (i - 0.5)};
		player_set = 1;
	}
	else
		return (0);
	if (c == 'N')
		map->player.dir = (t_vec2f){.x = 0, .y = -1};
	else if (c == 'S')
		map->player.dir = (t_vec2f){.x = 0, .y = 1};
	else if (c == 'E')
		map->player.dir = (t_vec2f){.x = 1, .y = 0};
	else if (c == 'W')
		map->player.dir = (t_vec2f){.x = -1, .y = 0};
	return (1);
}

int	parse_map(t_map *map, char **lines)
{
	char	**grid;
	int		i;
	int		j;

	grid = &lines[find_grid_start(lines) + 1];
	init_mapgrid(map, grid);
	i = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (grid[i][++j] && grid[i][j] != '\n')
		{
			if (!add_map_elem(map, grid, i, j))
				return (0);
		}
		while (j < map->size.x)
			map->grid[i][j++] = EMPTY;
	}
	return (1);
}
