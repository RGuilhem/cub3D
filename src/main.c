/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:08:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/17 14:23:44 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int	init_gui(t_gui *gui)
{
	gui->mlx = mlx_init();
	gui->mlx_win = mlx_new_window(gui->mlx, WIN_W, WIN_H, "cub3D");
	gui->screen.img = mlx_new_image(gui->mlx, WIN_W, WIN_H);
	gui->screen.address = mlx_get_data_addr(gui->screen.img,
			&gui->screen.bpp, &gui->screen.ll, &gui->screen.endian);
	gui->background.img = mlx_new_image(gui->mlx, WIN_W, WIN_H);
	gui->background.address = mlx_get_data_addr(gui->background.img,
			&gui->background.bpp, &gui->background.ll, &gui->background.endian);
	return (1);
}

static void	reset_image(t_gui *gui, t_frame *frame)
{
	int	x;
	int	y;

	mlx_destroy_image(gui->mlx, frame->img);
	frame->img = mlx_new_image(gui->mlx, WIN_W, WIN_H);
	frame->address = mlx_get_data_addr(frame->img,
			&frame->bpp, &frame->ll, &frame->endian);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			put_pixel(&gui->screen, x, y, 0xFF000000);
	}
}

static int	render_frame(t_data *data)
{
	t_gui		*gui;
	t_map		*map;

	gui = data->gui;
	map = data->map;
	apply_events(data);
	handle_mice(gui, map, 0);
	reset_image(gui, &gui->screen);
	mlx_put_image_to_window(gui->mlx, gui->mlx_win, gui->background.img, 0, 0);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, gui->screen.img);
	create_rays(map);
	cast_rays(gui, map);
	mlx_put_image_to_window(gui->mlx, gui->mlx_win, gui->screen.img, 0, 0);
	draw_minimap(gui, map);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, gui->mlx_win);
	return (1);
}

static void	print_map(t_map *map)
{
	int	i;
	int	j;

	printf("\nLoaded map:\n");
	i = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
			printf("%c", map->grid[i][j]);
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_gui	gui;
	t_map	map;
	t_data	data;

	if (argc != 2)
		return (put_error("Error: Invalid number of arguments"));
	map = (t_map){.tex_setup = 0, .grid_setup = 0};
	data = (t_data){.gui = &gui, .map = &map};
	gui.minimap_setup = 0;
	init_gui(&gui);
	if (!map_load(&gui, &map, argv[1]))
		exit_program(&data);
	print_map(&map);
	init_minimap(&gui, &map);
	setup_background(&gui, &map);
	define_angle_of_rays(&map);
	setup_events(&data);
	mlx_loop_hook(gui.mlx, render_frame, &data);
	mlx_loop(gui.mlx);
	return (0);
}
