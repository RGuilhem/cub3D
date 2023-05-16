/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:51:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 10:32:41 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"

static int	color_from_rgb(int r, int g, int b)
{
	int	color;

	color = 0;
	color |= r << (sizeof(char) * 2);
	color |= g << sizeof(char);
	color |= b;
	return (color);
}

static void	init_rgb_from_line(int *r, int *g, int *b, char *line)
{
	int		i;
	char	*end;

	(void) g;
	(void) b;
	i = -1;
	while (!ft_isdigit(line[++i]))
	{
		end = ft_strchr(&line[i], ',');
		if (end)
		{
			*end = '\0';
			*r = ft_atoi(&line[i]);
			*end = ',';
		}
	}
}

int	parse_colors(t_map *map, char **lines)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (lines[i] && lines[i][0] != 'F')
		i++;
	init_rgb_from_line(&r, &g, &b, lines[i]);
	map->f_color = color_from_rgb(r, g, b);
	i = 0;
	while (lines[i] && lines[i][0] != 'C')
		i++;
	init_rgb_from_line(&r, &g, &b, lines[i]);
	map->c_color = color_from_rgb(r, g, b);
	return (1);
}
