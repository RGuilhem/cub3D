/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:02 by graux             #+#    #+#             */
/*   Updated: 2023/04/03 16:19:16 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include "../include/level.h"
#include "../include/libft.h"

int	main(int argc, char *argv[])
{
	t_level	*level;

	(void) argv;
	(void) level;
	if (argc == 2)
	{
		if (!level_load(&level, argv[1]))
		{
			//TODO level_destroy
			return (1);
		}
	}
	else
		error_put("Invalid number of arguments: please provide the level path");
	return (0);
}
