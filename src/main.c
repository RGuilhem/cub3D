/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:08:52 by graux             #+#    #+#             */
/*   Updated: 2023/05/05 11:32:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"

int	main(int argc, char *argv[])
{
	t_gui	gui;

	(void) argc;
	(void) argv;
	gui.mlx = mlx_init();
	gui.mlx_win = mlx_new_window(gui.mlx, WIN_W, WIN_H, "cub3D");
	mlx_loop(gui.mlx);
	return (0);
}
