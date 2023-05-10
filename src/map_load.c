/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:36 by graux             #+#    #+#             */
/*   Updated: 2023/05/10 11:49:43 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"

static int	check_suffix(char *map_path)
{
	return (ft_strnstr(map_path, ".cub", ft_strlen(map_path)) != 0);
}

static int	parse_colors(t_map *map, char **lines)
{
	int	i;

	i = 0;
	while (lines[i] && lines[i][0] != 'F')
		i++;
	while (lines[i] && lines[i][0] != 'C')
		i++;
	return (1);
}

static int	parse_textures(t_map *map, char **lines)
{
	return (1);
}

static int	parse_map(t_map *map, char **lines)
{
	return (1);
}

int	map_load(t_map *map, char *map_path)
{
	char	**lines;

	if (!check_suffix(map_path))
		return (0);
	read_lines(map_path, &lines);
	if (!lines)
		return (0);
	if (!parse_colors(map, lines) || !parse_textures(map, lines)
		|| !parse_map(map, lines))
		return (0); // TODO cleanup in case of error
	return (1);
}
