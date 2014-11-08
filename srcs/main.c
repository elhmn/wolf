/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 17:24:02 by bmbarga          ###   ########.fr       */
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

static void	init_env(t_env *env)
{
	env->win = NULL;
	env->mlx = NULL;

	if (!(env->mlx = mlx_init()))
		check_errors(MALLOC, "env->mlx", "main.c");
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGH, "wolf3d")))
		check_errors(MALLOC, "env->win", "main.c");
}

static void close_mlx(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);	
}

void	new_lay(t_env *env, t_lay *lay, t_uint depht)
{
	if (!lay)
		if (!(lay = (t_lay*)malloc(sizeof(lay))))
			check_errors(MALLOC, "lay", "main.c");
	if (lay && env && env->mlx)
	{
		if (!(lay->img = mlx_new_image(env->mlx, WIDTH, HEIGH)))
			check_errors(NUL, "lay->img", "main.c");
		lay->depht = depht;
	}
}

int		main(int ac, char **av)
{
	t_env	env;
	t_lay	bg_lay;
	
	/*** ONLY FOR TEST ***/
	char	map[11][11] = { {"1111111111\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000020001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1111111111\0"},
							{0}
							};
	/******* TEST *******/

	init_env(&env);
	new_lay(&env, &bg_lay, 5000);
	print_map(map, 10);
	if (ac)
	{
		av = av;
		mlx_loop(env.mlx);
	}
	close_mlx(&env);
	return (0);
}
