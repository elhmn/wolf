/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 19:46:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "libft.h"
#include "check_errors.h"

static void	print_map(char map[][11], t_uint h)//, t_uint w)
{
	t_uint	i;
//	t_uint	j;

	i = 0;
//	j = 0;
	while (i < h)
	{
//		j = 0;
//		while (j < w)
//		{
			ft_putendl(map[i]);
//			j++;
//		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env		env;
	t_screen 	screen;
	t_lay		bg_lay;
	t_cam		cam;

	/*** ONLY FOR TEST ***/
	char	map[11][11] = { {"1111111111\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1111111111\0"},
							{0}
							};
	/******* TEST *******/

	init_env(&env);
	new_lay(&env, &bg_lay, 5000);
	init_cam(&cam);
	init_screen(&screen);
	print_cam(&cam);
	print_screen(&screen);
	print_map(map, 10);
	if (ac)
	{
		av = av;
		mlx_loop(env.mlx);
	}
	close_mlx(&env);
	return (0);
}
