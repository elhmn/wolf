/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/11 02:40:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"
#include <mlx.h>

static void	get_vlen(t_cam *cam, t_ray *ray, char map[][11])
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

void		raycaster(t_env *env, t_cam *cam, char map[][11])
{
	float		ang_strt;
	float		ang_end;
	float		inc;
	t_ray		ray;
	char		*img_map;
	int			bpp = 32;

	cam->i = 0;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGH);
	img_map = (char*)mlx_get_data_addr(env->img, &bpp, 4 * WIDTH, 1);
	if (!env || !cam)
		check_errors(NUL, "env || cam", "raycaster.c");
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&ray, ang_strt);
		get_vlen(cam, &ray, map);
		ray.v_len = ray.len * (float)(cos(ang_strt - cam->direction));
		cam->virtual_h = (float)(cam->dist_proj * (HEIGH / 2)) / ray.v_len;
		draw(env, cam);
		ang_strt -= inc;
	}
}
