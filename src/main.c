/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:08:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 13:08:58 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <unistd.h>

static int	render_frame(t_data *data)
{
	apply_events(data);
	sleep(1);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_gui	gui;
	t_map	map;
	t_data	data;

	(void) argc;
	(void) argv;
//	map_load(&map, argv[1]);
	map.player.dir = (t_vec2f){.x = 1, .y = 0};
	gui.mlx = mlx_init();
	gui.mlx_win = mlx_new_window(gui.mlx, WIN_W, WIN_H, "cub3D");
	setup_events(&gui);
	data = (t_data){.gui = &gui, .map = &map};
	mlx_loop_hook(gui.mlx, render_frame, &data);
	mlx_loop(gui.mlx);
	return (0);
}
