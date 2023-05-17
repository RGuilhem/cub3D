/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:26:46 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/17 09:51:05 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	cleanup_map(t_gui *gui, t_map *map)
{
	int	i;

	i = -1;
	while (++i < END_MAP_DIR)
		mlx_destroy_image(gui->mlx, map->textures[i].img);
}

void	cleanup_gui(t_gui *gui)
{
	mlx_destroy_image(gui->mlx, gui->screen.img);
	mlx_destroy_image(gui->mlx, gui->background.img);
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

	i = -1;
	while (++i < size)
		free(tab[i]);
	free(tab);
	return (0);
}
