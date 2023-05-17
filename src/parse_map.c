/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:53:42 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 13:47:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"
#include <limits.h>

static int	find_grid_start(char **lines)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	while (lines[++i] && num < 6)
	{
		if (lines[i][0] != '\n')
			num++;
	}
	while (lines[i])
	{
		if (lines[i][0] != '\n')
			break ;
		i++;
	}
	return (i);
}

static int	init_mapgrid(t_map *map, char **lines)
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
	map->size = (t_vec2i){.x = max + 1, .y = i + 2};
	map->grid = malloc(sizeof(char *) * map->size.y);
	if (!map->grid)
		return (0);
	map->grid_setup = 1;
	i = -1;
	while (++i < map->size.y)
	{
		map->grid[i] = ft_calloc(map->size.x, sizeof(char));
		if (!map->grid[i])
			return (0);
		ft_memset(map->grid[i], '0', map->size.x);
	}
	return (1);
}

static void	set_map_player_dir(t_map *map, char *c)
{
	if (*c == 'N')
		map->player.dir = (t_vec2f){.x = 0, .y = -1};
	else if (*c == 'S')
		map->player.dir = (t_vec2f){.x = 0, .y = 1};
	else if (*c == 'E')
		map->player.dir = (t_vec2f){.x = 1, .y = 0};
	else if (*c == 'W')
		map->player.dir = (t_vec2f){.x = -1, .y = 0};
}

static int	add_map_elem(t_map *map, char **grid, int i, int j)
{
	static int	player_set;
	char		c;

	c = grid[i][j];
	i++;
	j++;
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
	set_map_player_dir(map, &c);
	return (1);
}

int	parse_map(t_map *map, char **lines)
{
	char	**grid;
	int		i;
	int		j;

	grid = &lines[find_grid_start(lines)];
	if (!init_mapgrid(map, grid))
		return (1);
	i = -1;
	while (++i < map->size.y - 2)
	{
		j = -1;
		while (grid[i][++j] && grid[i][j] != '\n')
		{
			if (!add_map_elem(map, grid, i, j))
				return (0);
		}
		while (j < map->size.x - 1)
		{
			map->grid[i + 1][j + 1] = EMPTY;
			j++;
		}
	}
	return (1);
}
