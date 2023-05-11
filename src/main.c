/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:08:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/11 10:32:24 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"

int	main(int argc, char *argv[])
{
	t_gui	gui;
	t_map	map;
	t_frame	frame;

	(void) argc;
	(void) argv;
//	map_load(&map, argv[1]);
	map.player.dir.x = 1;
	map.player.dir.y = 0;
	gui.mlx = mlx_init();
	gui.mlx_win = mlx_new_window(gui.mlx, WIN_W, WIN_H, "cub3D");
	frame.img = mlx_new_image(gui.mlx, 1280, 720);
	frame.address = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	put_pixel(&frame, 100, 100, 0x00ff0000);
	mlx_put_image_to_window(gui.mlx, gui.mlx_win, frame.img, 0, 0);
	mlx_loop(gui.mlx);
	return (0);
}
