/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/09 11:05:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.c"

static double	mes_ang(double ang)
{
	if (ang > 0. && ang <= M_PI / 2.)
		return (ang);
	if (ang > M_PI / 2. && ang <= M_PI)
		return (M_PI - ang);
	if (ang > M_PI && ang < (3. * M_PI) / 2.)
		return (ang - M_PI);
	if (ang >= (3. * M_PI) / 2. && ang <= 2. * M_PI)
		return ((2. * M_PI) - ang);
}

static double	inter_hor(t_cam *cam, t_ray *ray, char **map)
{
	double	port_1;
	t_uint	h;
	t_uint	x;
	t_uint	y;
	t_uint	inc_x;

	x = (t_uint)cam->pos.x % WALL_W;
	y = (t_uint)cam->pos.y % WALL_H;
	if (ray->direction == M_PI || ray->direction == 0.
			|| ray->direction == 2. * M_PI)
		return (0);
	if (ray->direction > 0. && ray->direction < M_PI)
		h = ray->pos.y % WALL_H;
	else
		h = WALL_H - (ray->pos.y % WALL_H);
	port_1 = (double)h / sin(mes_ang(ray->direction));
	//si block(intersct) != MUR && block(intersct) != map_limit
	if (map[][])
	{
		port_1 += (double)WALL_H / sin(mes_ang(ray->direction));
		while ()
		{

		}
	}
	return (port_1);
}

static double	inter_vert(t_cam *cam, t_ray *ray, char **map)
{

	return ();
}

static double	ray_len(t_cam *cam, t_ray *ray, char **map)
{
	if (!cam || !map)
		check_errors(NUL, "cam || map", "raytracer.c");

	return ();	
}

void			ray_caster(t_env *env, t_cam *cam, char **map)
{
	double		ang_strt;
	double		ang_end;
	double		inc;
	t_ray		*ray;

	ray = NULL;
	if (!env || !cam)
		check_errors(NUL, "env || cam", "raycaster.c");
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = (double)(cam->champs / (double)WIDTH);
	while (ang_strt < ang_end)
	{
		init_ray(ray, ang_strt);
		//determiner la distance |cam-obj|
		//determiner la distance |cam-obj| virtuelle
		//determiner la hauteur de l obj a l ecran
		//affichage
		ang_strt += 	inc;
		free(ray);
	}
}
