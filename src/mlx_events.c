/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:16:59 by graux             #+#    #+#             */
/*   Updated: 2023/05/16 16:18:18 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <stdio.h>

int	reg_keydown(int keycode, t_gui *gui)
{
	int	i;

	i = -1;
	while (++i < MAX_KEYS)
	{
		if (gui->keys_pressed[i] == keycode)
			return (1);
	}
	i = -1;
	while (++i < MAX_KEYS)
	{
		if (gui->keys_pressed[i] == KEY_EMPTY)
		{
			gui->keys_pressed[i] = keycode;
			return (1);
		}
	}
	return (0);
}

int	reg_keyup(int keycode, t_gui *gui)
{
	int	i;

	i = -1;
	while (++i < MAX_KEYS)
	{
		if (gui->keys_pressed[i] == keycode)
		{
			gui->keys_pressed[i] = KEY_EMPTY;
			return (1);
		}
	}
	return (0);
}

void	init_keys_list(t_gui *gui)
{
	int	i;

	i = -1;
	while (++i < MAX_KEYS)
		gui->keys_pressed[i] = KEY_EMPTY;
}

void	apply_events(t_data *data)
{
	int		i;
	t_gui	*gui;
	t_map	*map;

	i = -1;
	gui = data->gui;
	map = data->map;
	while (++i < MAX_KEYS)
	{
		if (gui->keys_pressed[i] == KEY_W)
			move_player(map, &map->player, gui->keys_pressed[i]);
		else if (gui->keys_pressed[i] == KEY_S)
			move_player(map, &map->player, gui->keys_pressed[i]);
		else if (gui->keys_pressed[i] == KEY_A)
			move_player(map, &map->player, gui->keys_pressed[i]);
		else if (gui->keys_pressed[i] == KEY_D)
			move_player(map, &map->player, gui->keys_pressed[i]);
		else if (gui->keys_pressed[i] == L_ARROW
			|| gui->keys_pressed[i] == R_ARROW)
			rotate_player(&map->player, gui->keys_pressed[i], 1);
	}
}

void	setup_events(t_gui *gui)
{
	init_keys_list(gui);
	mlx_hook(gui->mlx_win, 2, 0, reg_keydown, gui);
	mlx_hook(gui->mlx_win, 3, 0, reg_keyup, gui);
}
