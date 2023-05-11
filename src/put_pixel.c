/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:36:26 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 13:47:57 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"

void	put_pixel(t_frame *fra, int x, int y, int color)
{
	char	*pix;

	pix = fra->address + (y * fra->ll + x * (fra->bpp / 8));
	*(unsigned int *) pix = color;
}
