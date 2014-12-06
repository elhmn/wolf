/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/06 11:41:13 by bmbarga          ###   ########.fr       */
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
}

void		raycaster(t_wolf *wolf, t_cam *cam, char **map)
{
	float		ang_strt;
	float		ang_end;
	float		inc;
	t_ray		ray;
	int			lost_l;

	lost_l = 0;
	if (!wolf->env || !cam)
		check_errors(NUL, "wolf->env || cam", "raycaster.c");
	cam->i = 0;
	wolf->env->img = mlx_new_image(wolf->env->mlx, WIDTH, HEIGH);
//	wolf->i_light = 0;
//	wolf->i_shad = 0;
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&ray, mes_princ(ang_strt));
		get_vlen(cam, &ray, map, wolf);
		ray.v_len = ray.len * (float)(cos(ang_strt - cam->direction));
		cam->virtual_h = (float)(cam->dist_proj * (HEIGH / 2)) / ray.v_len;
		if (cam->virtual_h > HEIGH)
			cam->virtual_h = HEIGH;
		lost_l = (int)((G_LIGHT * (int)(cam->virtual_h)) / U_LONG);
//		set_color(wolf->col_sky);
		set_color(wolf->col_wl);
		low_light(wolf->col_wl, (unsigned)lost_l, 1);
//		set_color(wolf->col_gd);
//		wolf->col_wl->color -= (cam->virtual_h / 256);
		draw_img(wolf, cam);
		ang_strt -= inc;
		//(wolf->i_shad)++;
	}
	mlx_put_image_to_window(wolf->env->mlx, wolf->env->win, wolf->env->img, 0, 0);
	mlx_destroy_image(wolf->env->mlx, wolf->env->img);
}
