/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/20 02:09:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "check_errors.h"
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

float		mes_princ(float ang)
{
	if (ang < 0.)
		return ((2. * M_PI) + ang);
	else if (ang > 2. * M_PI)
		return (ang - (2. * M_PI));
	return (ang);
}

static void aux_get_vlen(t_wolf *wolf, float len_x, float len_y, t_ray *ray)
{
	if (len_x <= len_y)
	{
		ray->len = len_x;
		wolf->col_wl->color = ray->col_h;
	}
	else
	{
		ray->len = len_y;
		wolf->col_wl->color = ray->col_v;
	}
}

static void	get_vlen(t_cam *cam, t_ray *ray, char **map, t_wolf *wolf)
{
	float	len_x;
	float	len_y;

	len_x = inter_hor(cam, ray, map);
	len_y = inter_vert(cam, ray, map);
	if (len_x == 0 && len_y != 0)
	{
		ray->len = len_y;
		wolf->col_wl->color = ray->col_v;
	}
	else if (len_y == 0 && len_x != 0)
	{
		ray->len = len_x;
		wolf->col_wl->color = ray->col_h;
	}
	else
		aux_get_vlen(wolf, len_x, len_y, ray);
}

static void	aux_caster(t_wolf *wolf, t_cam *cam)
{
	int		lost_l;

	lost_l = 0;
	if (cam->virtual_h > HEIGH)
		cam->virtual_h = HEIGH;
	lost_l = (int)(((int)G_LIGHT * (int)(wolf->ray.v_len)) / (int)U_LONG);
	set_color(wolf->col_wl);
	low_light(wolf->col_wl, (t_uint)lost_l, -1);
	wolf->col_gd->color = COL_GD;
	set_color(wolf->col_gd);
	wolf->col_sky->color = COL_SKY;
	set_color(wolf->col_sky);
	draw_img(wolf, cam, wolf->ray);
}

void		raycaster(t_wolf *wolf, t_cam *cam, char **map)
{
	float		ang_strt;
	float		ang_end;
	float		inc;

	if (!wolf->env || !cam)
		check_errors(NUL, "wolf->env || cam", "raycaster.c");
	cam->i = 0;
	wolf->env->img = mlx_new_image(wolf->env->mlx, WIDTH, HEIGH);
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&(wolf->ray), mes_princ(ang_strt));
		get_vlen(cam, &(wolf->ray), map, wolf);
		wolf->ray.v_len = wolf->ray.len *
			(float)(cos(ang_strt - cam->direction));
		cam->virtual_h = (float)(cam->dist_proj
			* (HEIGH / 2)) / wolf->ray.v_len;
		aux_caster(wolf, cam);
		ang_strt -= inc;
	}
	mlx_put_image_to_window(wolf->env->mlx,
		wolf->env->win, wolf->env->img, 0, 0);
	mlx_destroy_image(wolf->env->mlx, wolf->env->img);
}
