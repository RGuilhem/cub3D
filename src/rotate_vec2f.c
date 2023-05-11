/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec2f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:51:10 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 14:56:25 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	rotate_vec2f(t_vec2f *vec, t_mat2x2 *mat)
{
	t_vec2f	tmp;

	tmp = (t_vec2f){.x = vec->x, .y = vec->y};
	vec->x = tmp.x * mat->elem1_1 + tmp.y * mat->elem1_2;
	vec->y = tmp.x * mat->elem2_1 + tmp.y * mat->elem2_2;
}
