/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:36 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 09:01:01 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"

static int	check_suffix(char *map_path)
{
	return (ft_strnstr(map_path, ".cub", ft_strlen(map_path)) != 0);
}

int	map_load(t_gui *gui, t_map *map, char *map_path)
{
	char	**lines;

	if (!check_suffix(map_path))
		return (0);
	read_lines(map_path, &lines);
	if (!lines)
		return (0);
	if (!parse_colors(map, lines) || !parse_textures(gui, map, lines)
		|| !parse_map(map, lines))
		return (0); // TODO cleanup in case of error
	return (1);
}
