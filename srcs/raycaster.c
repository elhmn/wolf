/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/09 19:59:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"
#include <mlx.h>
#include <stdio.h>

static float	mes_ang(float ang)
{
	if (ang > 0. && ang < M_PI / 2.)
		return (ang);
	if (ang >= M_PI / 2. && ang <= M_PI)
		return (M_PI - ang);
	if (ang > M_PI && ang < (3. * M_PI) / 2.)
		return (ang - M_PI);
	if (ang >= (3. * M_PI) / 2. && ang <= 2. * M_PI)
		return ((2. * M_PI) - ang);
	return (0);
}

void			map_pos_vert(t_cam *cam, t_ray *ray, t_pos *pos, t_uint w)
{
	float		h;

	h = sqrt(pow(ray->len, 2) - pow(w, 2));
//	printf("w = [%.50lf]\n", w);
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2)
		pos->x = (cam->pos.x - w) / WALL_W;
	else
		pos->x = (cam->pos.x + w) / WALL_W;
	if (ray->direction >= 0. && ray->direction <= M_PI)
		pos->y = (cam->pos.x - h) / WALL_H;
	else
		pos->y = (cam->pos.x + h) / WALL_H;
}

static float	inter_vert(t_cam *cam, t_ray *ray, char map[][11])
{
	t_uint	w;
	t_pos	pos;
	float	port_2;

//	printf("ray->dir = [%.50lf]\n", ray->direction);
	if ((int)DEG(ray->direction) == (int)DEG(M_PI / 2.)
			|| (int)DEG(ray->direction) == (int)DEG((3. * M_PI) / 2))
//	{
//		ft_putendl("##############################");
		return (0);
//	}
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2)
		w = cam->pos.x % WALL_W;
	else
		w = WALL_W - (cam->pos.x % WALL_W);
	ray->len = (float)w / cos(mes_ang(ray->direction));
//	printf("ray->len = [%.50lf]\n", ray->len);
	map_pos_vert(cam, ray, &pos, w);
//	printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);
	if (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
		|| pos.x >= MAP_W || pos.x < 0))
	{
		port_2 = (float)WALL_W / cos(mes_ang(ray->direction));
		ray->len += port_2;
		while (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
			|| pos.x >= MAP_W || pos.x < 0))
		{
			ray->len += port_2;
			w += WALL_W;
			map_pos_vert(cam, ray, &pos, w);
//	printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);
		}
	}
	return (ray->len);
}

void			map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h)
{
	float		w;

	w = sqrt(pow(ray->len, 2) - pow(h, 2));
//	printf("w = [%.50lf]\n", w);
	if (ray->direction > 0. && ray->direction < M_PI)
		pos->y = (cam->pos.y - h) / WALL_H;
	else
		pos->y = (cam->pos.y + h) / WALL_H;
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
		pos->x = (cam->pos.x - w) / WALL_W;
	else
		pos->x = (cam->pos.x + w) / WALL_W;
}

static float	inter_hor(t_cam *cam, t_ray *ray, char map[][11])
{
	t_uint	h;
	t_pos	pos;
	float	port_2;

//	printf("ray->dir = [%.50lf]\n", ray->direction);
	if ((int)DEG(ray->direction) == (int)DEG(M_PI)
			|| (int)DEG(ray->direction) == 0
			|| (int)DEG(ray->direction) == (int)DEG(2. * M_PI))
//	{
//		ft_putendl("##############################");
		return (0);
//	}
	if (ray->direction > 0. && ray->direction < M_PI)
		h = cam->pos.y % WALL_H;
	else
		h = WALL_H - (cam->pos.y % WALL_H);
	ray->len = (float)h / sin(mes_ang(ray->direction));
//	printf("ray->len = [%.50lf]\n", ray->len);
	map_pos_hor(cam, ray, &pos, h);
//	printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);
	if (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
		|| pos.x >= MAP_W || pos.x < 0))
	{
		port_2 = (float)WALL_H / sin(mes_ang(ray->direction));
		ray->len += port_2;
		while (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
			|| pos.x >= MAP_W || pos.x < 0))
		{
			ray->len += port_2;
			h += WALL_H;
			map_pos_hor(cam, ray, &pos, h);
//	printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);
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

void			raycaster(t_env *env, t_cam *cam, char map[][11])
{
	float		ang_strt;
	float		ang_end;
	float		inc;
	t_ray		ray;
	t_pos		len;
	int			i;
	int			j;
	int			lim;

	i = 0;
	if (!env || !cam)
		check_errors(NUL, "env || cam", "raycaster.c");
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = (float)(cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
//		printf("ang_strt = [%d]\n", (int)(DEG(ang_strt)));
		init_ray(&ray, ang_strt);
		len.y =	(t_uint)inter_vert(cam, &ray, map);
		len.x = (t_uint)inter_hor(cam, &ray, map);
		if (len.x == 0 && len.y != 0)
			ray.len = len.y;
		else if (len.y == 0 && len.x != 0)
			ray.len = len.x;
		else
			ray.len = (float)((len.x < len.y) ? len.x : len.y);
		printf("len.x = [%d] && len.y = [%d]\n", len.x, len.y);
//		printf("AVANT :: ray->len = [%lf]\n", ray.len);
		ray.len = ray.len * (float)(cos(cam->champs / 2.));
		cam->virtual_h = (float)(cam->dist_proj * WALL_H) / ray.len;
		lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
		printf("cam->virtual_h = [%d]\n", (t_uint)cam->virtual_h);
		j = 0;
		while (j <= lim)
			mlx_pixel_put(env->mlx, env->win, i, j++, 0x00FFFF);
		while (j <	(t_uint)((float)lim + cam->virtual_h))
			mlx_pixel_put(env->mlx, env->win, i, j++, 0xFF00FF);
		while (j <= HEIGH)
			mlx_pixel_put(env->mlx, env->win, i, j++, 0x00FFFF);
		printf("APRES :: ray->len = [%f]\n", ray.len);
		//determiner la distance |cam-obj|
		//determiner la distance |cam-obj| virtuelle
		//determiner la hauteur de l obj a l ecran
		//affichage
		ang_strt -= inc;
		i++;
//		printf("ang_strt += inc = [%.15lf]\n", ang_strt);
	}
}
