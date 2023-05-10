/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:51:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/10 11:52:13 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	parse_colors(t_map *map, char **lines)
{
	int	i;

	i = 0;
	while (lines[i] && lines[i][0] != 'F')
		i++;
	while (lines[i] && lines[i][0] != 'C')
		i++;
	return (1);
}
