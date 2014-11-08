/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 22:48:53 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 22:49:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"

void	init_env(t_env *env)
{
	env->win = NULL;
	env->mlx = NULL;

	if (!(env->mlx = mlx_init()))
		check_errors(MALLOC, "env->mlx", "init_wolf_var.c");
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGH, "wolf3d")))
		check_errors(MALLOC, "env->win", "init_wolf_var.c");
}

void	close_mlx(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);	
}

void	new_lay(t_env *env, t_lay *lay, t_uint depht)
{
	if (!lay)
		if (!(lay = (t_lay*)malloc(sizeof(lay))))
			check_errors(MALLOC, "lay", "init_wolf_var.c");
	if (lay && env && env->mlx)
	{
		if (!(lay->img = mlx_new_image(env->mlx, WIDTH, HEIGH)))
			check_errors(NUL, "lay->img", "init_wolf_var.c");
		lay->depht = depht;
	}
}

void	init_cam(t_cam *cam)
{
	double	tan;

	if (!cam)
	{
		if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
			check_errors(MALLOC, "cam", "init_wolf_var.c");
	}
	cam->angle = CHAMPS;
	cam->direction = START_DIR;
	cam->pos.x = (WALL_W * 5) + (WALL_W / 2);
	cam->pos.y = (WALL_H * 4) + (WALL_H / 2);
	tan = (double)((double)sin((CHAMPS / 2.0)) / (double)cos((CHAMPS / 2.0)));
	cam->dist_proj = (t_uint)((double)(WIDTH / 2) / tan);
	cam->h_cam = WALL_H / 2;
}

void	init_screen(t_screen *screen)
{
	if (!screen)
	{
		if (!(screen = (t_screen*)malloc(sizeof(t_screen))))
			check_errors(MALLOC, "screen", "init_wolf_var.c");
	}
	screen->h = HEIGH;
	screen->w = WIDTH;
	screen->center.x = WIDTH / 2;
	screen->center.y = HEIGH / 2;
}
