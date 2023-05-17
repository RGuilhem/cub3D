/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:52:56 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 15:09:06 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

const char	*g_char_side[END_MAP_DIR] = {
[NO] = "NO", [SO] = "SO", [WE] = "WE", [EA] = "EA"};

static char	*find_texture_path(char	**lines, int side)
{
	int		i;
	int		j;
	int		pos_nl;

	i = -1;
	j = 2;
	while (lines[++i])
	{
		if (ft_strncmp(g_char_side[side], lines[i], 2) == 0)
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
	char		*p;
	t_vec2i		s;
	int			status;

	i = -1;
	map->tex_setup = 1;
	status = 1;
	while (++i < END_MAP_DIR)
	{
		p = find_texture_path(lines, i);
		map->textures[i].img = mlx_xpm_file_to_image(gui->mlx, p, &s.x, &s.y);
		if (!map->textures[i].img)
			status = 0;
		else
		{
			map->textures[i].address = mlx_get_data_addr(map->textures[i].img,
					&map->textures[i].bpp, &map->textures[i].ll,
					&map->textures[i].endian);
			printf("w: %d, h: %d -> path: %s\n", s.x, s.y, p);
		}
	}
	return (status);
}
