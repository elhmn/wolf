/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wolf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:40:16 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 17:47:04 by bmbarga          ###   ########.fr       */
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
		check_errors(MALLOC, "env->mlx", "main.c");
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGH, "wolf3d")))
		check_errors(MALLOC, "env->win", "main.c");
}

void	close_mlx(t_env *env)
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

void	init_cam(t_cam *cam)
{
	if (!cam)
	{
		if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
			check_errors(MALLOC, "cam", "main.c");
	}
	cam->angle = CHAMPS;
	cam->direction = START_DIR;
}
