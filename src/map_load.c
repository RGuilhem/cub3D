/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:36 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 13:10:52 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"

static void	free_lines(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
}

static int	check_suffix(char *map_path)
{
	return (ft_strnstr(map_path, ".cub", ft_strlen(map_path)) != 0);
}

int	map_load(t_gui *gui, t_map *map, char *map_path)
{
	char	**lines;

	if (!check_suffix(map_path))
		return (put_error("invalid file suffix"));
	read_lines(map_path, &lines);
	if (!lines)
		return (put_error("file could not be read"));
	if (!parse_colors(map, lines))
	{
		free_lines(lines);
		return (put_error("invalid color format"));
	}
	if (!parse_textures(gui, map, lines))
	{
		free_lines(lines);
		return (put_error("invalid textures"));
	}
	if (!parse_map(map, lines) || !check_map(map))
	{
		free_lines(lines);
		return (put_error("reading map"));
	}
	free_lines(lines);
	return (1);
}
