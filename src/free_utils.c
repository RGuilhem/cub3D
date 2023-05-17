/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:26:46 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/17 14:00:21 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	exit_program(t_data *data)
{
	cleanup_map(data->gui, data->map);
	cleanup_gui(data->gui);
	exit(EXIT_SUCCESS);
}

void	cleanup_map(t_gui *gui, t_map *map)
{
	int	i;

	if (map->tex_setup)
	{
		i = -1;
		while (++i < END_MAP_DIR)
		{
			if (map->textures[i].img)
				mlx_destroy_image(gui->mlx, map->textures[i].img);
		}
	}
	if (map->grid_setup)
		free_ppsize(map->grid, map->size.y);
}

void	cleanup_gui(t_gui *gui)
{
	mlx_destroy_image(gui->mlx, gui->screen.img);
	mlx_destroy_image(gui->mlx, gui->background.img);
	if (gui->minimap_setup)
		mlx_destroy_image(gui->mlx, gui->minimap.img);
	mlx_destroy_window(gui->mlx, gui->mlx_win);
}

int	put_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (0);
}

int	free_ppsize(char **tab, int size)
{
	int	i;

	if (!tab)
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!tab[i])
			break ;
		free(tab[i]);
	}
	free(tab);
	return (0);
}
