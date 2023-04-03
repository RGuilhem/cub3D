/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:59:12 by graux             #+#    #+#             */
/*   Updated: 2023/04/03 16:19:50 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# define L_EMPTY 0
# define L_WALL 1
# define L_P_ORIENT_N 'N'
# define L_P_ORIENT_S 'S'
# define L_P_ORIENT_E 'E'
# define L_P_ORIENT_W 'W'

typedef struct s_rgb_col
{
	char	r;
	char	g;
	char	b;
}			t_rgb_col;

typedef struct s_level
{
	t_rgb_col	floor_color;
	t_rgb_col	ceiling_color;
	int			width;
	int			height;
	int			**map;
}			t_level;

//level management
void	level_destroy(t_level *level);

//level parsing
int		level_load(t_level **level, char *level_path);
int		level_print(t_level *level);

#endif
