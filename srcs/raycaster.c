/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/09 14:20:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.c"
#include <stdio.h>

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

void			map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h)
{
	double		w;

	w = sqrt(pow(ray->len) - pow(h));
	if (ray->direction > 0. && ray->direction < M_PI)
		pos->y = (cam->pos.y - h) / WALL_H;
	else
		pos->y = (cam->pos.y + h) / WALL_H;
	if (ray_direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
		pos->x = (w - cam->pos.x) / WALL_W;
	else
		pos->x = (w + cam->pos.x) / WALL_W;
}

static double	inter_hor(t_cam *cam, t_ray *ray, char map[][11])
{
	t_uint	h;
	t_pos	pos;
	t_uint	inc_x;
	double	port_2;

	if (ray->direction == M_PI || ray->direction == 0.
			|| ray->direction == 2. * M_PI)
		return (0);
	if (ray->direction > 0. && ray->direction < M_PI)
		h = ray->pos.y % WALL_H;
	else
		h = WALL_H - (ray->pos.y % WALL_H);
	ray->len = (double)h / sin(mes_ang(ray->direction));
	map_pos_hor(cam, ray, &pos, h);
	if (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
		|| pos.x >= MAP_W || pos.x < 0))
	{
		port_2 = (double)WALL_H / sin(mes_ang(ray->direction));
		ray->len += port_2;
		while (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
			|| pos.x >= MAP_W || pos.x < 0))
		{
			ray->len += port_2;
			h += WALL_H;
			map_pos_hor(cam, ray, &pos, h);
		}
	}
	return (ray->len);
}

/*
static double	inter_vert(t_cam *cam, t_ray *ray, char **map)
{

	return ();
}
*/

/*
static double	ray_len(t_cam *cam, t_ray *ray, char **map)
{
	if (!cam || !map)
		check_errors(NUL, "cam || map", "raytracer.c");

	return ();
}
*/

void			ray_caster(t_env *env, t_cam *cam, char map[][11])
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
	while (ang_strt > ang_end)
	{
		init_ray(ray, ang_strt);
		inter_hor(cam, ray, map);
		printf("inter_hor = [%lf]\n", ray->len);
		//determiner la distance |cam-obj|
		//determiner la distance |cam-obj| virtuelle
		//determiner la hauteur de l obj a l ecran
		//affichage
		ang_strt += inc;
		if (ang)
		free(ray);
	}
}
