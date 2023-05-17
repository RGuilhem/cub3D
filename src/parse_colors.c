/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:51:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 13:38:50 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../libft/includes/libft.h"

static int	color_from_rgb(int r, int g, int b)
{
	int	color;

	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}

static void	init_val(int *val, char *line, int *i, int last)
{
	char	*end;

	if (!last)
	{
		end = ft_strchr(&line[*i], ',');
		*end = '\0';
	}
	*val = ft_atoi(&line[*i]);
	*i += ft_strlen(&line[*i]);
	if (!last)
		*end = ',';
}

static void	init_rgb_from_line(int *r, int *g, int *b, char *line)
{
	int		i;

	i = -1;
	while (!ft_isdigit(line[++i]))
		;
	init_val(r, line, &i, 0);
	while (!ft_isdigit(line[++i]))
		;
	init_val(g, line, &i, 0);
	while (!ft_isdigit(line[++i]))
		;
	init_val(b, line, &i, 1);
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
	if (!lines[i])
		return (0);
	init_rgb_from_line(&r, &g, &b, lines[i]);
	map->f_color = color_from_rgb(r, g, b);
	i = 0;
	while (lines[i] && lines[i][0] != 'C')
		i++;
	if (!lines[i])
		return (0);
	init_rgb_from_line(&r, &g, &b, lines[i]);
	map->c_color = color_from_rgb(r, g, b);
	return (1);
}
