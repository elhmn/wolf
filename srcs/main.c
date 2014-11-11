/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/11 01:17:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "libft.h"
#include "check_errors.h"

static void	print_map(char map[][11], t_uint h)
{
	t_uint	i;

	i = 0;
	while (i < h)
	{
		ft_putendl(map[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env		env;
	t_screen 	screen;
	t_lay		bg_lay;
	t_obj		wall;
	t_cam		cam;

	char	map[11][11] = { {"1111111111\0"},
		{"1001001001\0"},
		{"1000001001\0"},
		{"1001010101\0"},
		{"1010000101\0"},
		{"1100010001\0"},
		{"1000000001\0"},
		{"1000100001\0"},
		{"1000000001\0"},
		{"1111111111\0"},
		{0}
	};

	init_env(&env);
	new_lay(&env, &bg_lay, 5000);
	init_cam(&cam);
	init_screen(&screen);
	init_wall(&wall);
	map[cam.pos.y / WALL_H][cam.pos.x / WALL_W] = CAM;
	print_cam(&cam);
	print_screen(&screen);
	print_obj(&wall);
	print_map(map, 10);
	raycaster(&env, &cam, map);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	if (ac)
	{
		av = av;
		mlx_loop(env.mlx);
	}
	close_mlx(&env);
	return (0);
}
