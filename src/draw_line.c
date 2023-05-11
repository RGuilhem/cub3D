/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:35:57 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 16:06:41 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>

static void	init_line(t_vec2f *dir, t_vec2f *a, t_vec2f *b, double *step)
{
	dir->x = b->x - a->x;
	dir->y = b->y - a->y;
	if (fabs(dir->x) >= fabs(dir->y))
		*step = fabs(dir->x);
	else
		*step = fabs(dir->y);
	dir->x /= *step;
	dir->y /= *step;
}

void	draw_line(t_frame *frame, t_vec2f *a, t_vec2f *b)
{
	t_vec2f	dir;
	double	step;
	t_vec2f	pos;
	int		i;

	init_line(&dir, a, b, &step);
	pos.x = a->x;
	pos.y = a->y;
	i = 0;
	while (++i <= step)
	{
		if (pos.x >= 0 && pos.x < WIN_W && pos.y >= 0 && pos.y < WIN_H)
			put_pixel(frame, pos.x, pos.y, 0x00FF0000);
		pos.x += dir.x;
		pos.y += dir.y;
	}
}
