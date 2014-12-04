/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/05 00:00:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "check_errors.h"
#include <stdio.h>

float		mes_princ(float ang)
{
	if (ang < 0.)
		return ((2. * M_PI) + ang);
	else if (ang > 2. * M_PI)
		return (ang - (2. * M_PI));
	return (ang);
}

static void	get_vlen(t_cam *cam, t_ray *ray, char **map)
{
	float	len_x;
	float	len_y;

	len_x = inter_hor(cam, ray, map);
	len_y = inter_vert(cam, ray, map);
	if (len_x == 0 && len_y != 0)
		ray->len = len_y;
	else if (len_y == 0 && len_x != 0)
		ray->len = len_x;
	else
		ray->len = (len_x <= len_y) ? len_x : len_y;
}

void		raycaster(t_env *env, t_cam *cam, char **map)
{
	float		ang_strt;
	float		ang_end;
	float		inc;
	t_ray		ray;

	if (!env || !cam)
		check_errors(NUL, "env || cam", "raycaster.c");
	cam->i = 0;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGH);
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&ray, mes_princ(ang_strt));
		get_vlen(cam, &ray, map);
		ray.v_len = ray.len * (float)(cos(ang_strt - cam->direction));
		cam->virtual_h = (float)(cam->dist_proj * (HEIGH / 2)) / ray.v_len;
		if (cam->virtual_h > HEIGH)
			cam->virtual_h = HEIGH;
		draw_img(env, cam);
		ang_strt -= inc;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
