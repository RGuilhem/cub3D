/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:08:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 16:25:20 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
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
	t_vec2f		real_dir;

	gui = data->gui;
	map = data->map;
	apply_events(data);
	reset_image(gui, &gui->screen);
	mlx_put_image_to_window(gui->mlx, gui->mlx_win, gui->background.img, 0, 0);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, gui->screen.img);
	real_dir = (t_vec2f){.x = map->player.pos.x + map->player.dir.x * 15,
		.y = map->player.pos.y + map->player.dir.y * 15};
	draw_line(&gui->screen, &map->player.pos, &real_dir);
	mlx_put_image_to_window(gui->mlx, gui->mlx_win, gui->screen.img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, gui->mlx_win);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_gui	gui;
	t_map	map;
	t_data	data;

	(void) render_frame;
	(void) argc;
	(void) argv;
//	map_load(&map, argv[1]);
	map.player.dir = (t_vec2f){.x = 1, .y = 0};
	map.player.pos = (t_vec2f){.x = 300, .y = 300};
	init_gui(&gui);
	setup_background(&gui, &map);
	setup_events(&gui);
	data = (t_data){.gui = &gui, .map = &map};
	mlx_loop_hook(gui.mlx, render_frame, &data);
	mlx_loop(gui.mlx);
	return (0);
}
