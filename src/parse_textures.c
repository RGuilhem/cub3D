/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:52:56 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 10:05:34 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <stdlib.h>
#include <stdio.h>

char	*find_texture_path(char	**lines, char side)
{
	int		i;
	int		j;
	int		pos_nl;

	i = -1;
	j = 2;
	while (lines[++i])
	{
		if (lines[i][0] == side)
		{
			while (lines[i][j] == ' ')
				j++;
			pos_nl = j;
			while (lines[i][pos_nl] && lines[i][pos_nl] != '\n')
				pos_nl++;
			lines[i][pos_nl] = '\0';
			return (&lines[i][j]);
		}
	}
	return (NULL);
}

int	parse_textures(t_gui *gui, t_map *map, char **lines)
{
	int			i;
	char		*path;
	const char	char_side[END_MAP_DIR] = {
	[NO] = 'N',
	[SO] = 'S',
	[WE] = 'W',
	[EA] = 'E'
	};
	int			w;
	int			h;

	i = -1;
	printf("Loading textures...\n");
	while (++i < END_MAP_DIR)
	{
		path = find_texture_path(lines, char_side[i]);
		printf("path: %s\n", path);
		map->textures[i].img = mlx_xpm_file_to_image(gui->mlx, path, &w, &h);
		map->textures[i].address = mlx_get_data_addr(map->textures[i].img,
				&map->textures[i].bpp, &map->textures[i].ll,
				&map->textures[i].endian);
		printf("w: %d, h: %d\n", w, h);
	}
	return (1);
}
