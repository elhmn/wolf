/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 08:09:48 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/10 18:24:03 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2)
		pos->x = (cam->pos.x - w) / WALL_W;
	else
		pos->x = (cam->pos.x + w) / WALL_W;
	if (ray->direction >= 0. && ray->direction <= M_PI)
		pos->y = (cam->pos.y - h) / WALL_H;
	else
		pos->y = (cam->pos.y + h) / WALL_H;
}

//	printf("w = [%.50lf]\n", w);

static float	inter_vert(t_cam *cam, t_ray *ray, char map[][11])
{
	t_uint	w;
	t_pos	pos;
	float	port_2;

//	printf("ray->dir = [%.50lf]\n", ray->direction);
	if ((int)DEG(ray->direction) == (int)DEG(M_PI / 2.)
			|| (int)DEG(ray->direction) == (int)DEG((3. * M_PI) / 2))
		return (0);
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2)
		w = cam->pos.x % WALL_W;
	else
		w = WALL_W - (cam->pos.x % WALL_W);
	ray->len = (float)w / cos(mes_ang(ray->direction));
	map_pos_vert(cam, ray, &pos, w);
//	printf("ray->len = [%f]\n", ray->len);
	//printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);
	port_2 = (float)WALL_W / cos(mes_ang(ray->direction));
	while (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
		|| pos.x >= MAP_W || pos.x < 0))
	{
			ray->len += port_2;
			w += WALL_W;
			map_pos_vert(cam, ray, &pos, w);
	}
	return (ray->len);
}

//	printf("ray->dir = [%.50lf]\n", ray->direction);
//	printf("ray->len = [%.50lf]\n", ray->len);
//	printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);
//	printf("pos.x = [%d] && pos.y = [%d]\n", pos.x, pos.y);

void			map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h)
{
	float		w;

	w = sqrt(pow(ray->len, 2) - pow(h, 2));
	if (ray->direction > 0. && ray->direction < M_PI)
		pos->y = (cam->pos.y - h) / WALL_H;
	else
		pos->y = (cam->pos.y + h) / WALL_H;
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
		pos->x = (cam->pos.x - w) / WALL_W;
	else
		pos->x = (cam->pos.x + w) / WALL_W;
}

//	printf("w = [%.50lf]\n", w);

static float	inter_hor(t_cam *cam, t_ray *ray, char map[][11])
{
	t_uint	h;
	t_pos	pos;
	float	port_2;

	//printf("ray->dir = [%.50lf]\n", ray->direction);
	if ((int)DEG(ray->direction) == (int)DEG(M_PI)
			|| (int)DEG(ray->direction) == 0
			|| (int)DEG(ray->direction) == (int)DEG(2. * M_PI))
		return (0);
	if (ray->direction > 0. && ray->direction < M_PI)
		h = cam->pos.y % WALL_H;
	else
		h = WALL_H - (cam->pos.y % WALL_H);
	ray->len = (float)h / sin(mes_ang(ray->direction));
	map_pos_hor(cam, ray, &pos, h);
	port_2 = (float)WALL_H / sin(mes_ang(ray->direction));
	while (!((map[pos.y][pos.x] == 1 || pos.y >= MAP_H || pos.y < 0)
		|| pos.x >= MAP_W || pos.x < 0))
	{
		{
			ray->len += port_2;
			h += WALL_H;
			map_pos_hor(cam, ray, &pos, h);
		}
	}
	return (ray->len);
}

//		ft_putendl("##############################");
//		printf("ray->len = [%.50lf]\n", ray->len);

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
	float		len_x;
	float		len_y;
	int			lim;
	int			i;
	int			j;
	int			color;

	color = 0xFF00FF;
	i = 0;
	if (!env || !cam)
		check_errors(NUL, "env || cam", "raycaster.c");
	ang_strt = cam->direction + (cam->champs / 2.0);
	ang_end = cam->direction - (cam->champs / 2.0);
	inc = ((float)cam->champs / (float)WIDTH);
	while (ang_strt >= ang_end)
	{
		init_ray(&ray, ang_strt);
		len_y =	inter_vert(cam, &ray, map);
		len_x = inter_hor(cam, &ray, map);
		if (len_x == 0 && len_y != 0)
			ray.len = len_y;
		else if (len_y == 0 && len_x != 0)
			ray.len = len_x;
		else
			ray.len = (len_x <= len_y) ? len_x : len_y;

		printf("len_x = [%f] && len_y = [%f]\n", len_x, len_y);
		printf("AVANT :: ray->len = [%f]\n", ray.len);
		if (len_x < len_y)
			printf("intersection horizontal\n");
		else
			printf("intersection vertical\n");

		ray.v_len = ray.len * (float)(cos(ang_strt - cam->direction));
		printf("APRES :: ray->v_len = [%f]\n", ray.v_len);
		cam->virtual_h = (float)(cam->dist_proj * WALL_H) / ray.v_len;
		lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
		j = 0;
		while (j <= lim)
			mlx_pixel_put(env->mlx, env->win, i, j++, 0x00FFFF);
		while (j <	(t_uint)((float)lim + cam->virtual_h))
			mlx_pixel_put(env->mlx, env->win, i, j++, color);
		while (j < HEIGH)
			mlx_pixel_put(env->mlx, env->win, i, j++, 0x00FFFF);
//		if (i < WIDTH / 2)
//			color -= 0x100FF;
//		else
//			color += 0x100FF;
		//determiner la distance |cam-obj|
		//determiner la distance |cam-obj| virtuelle
		//determiner la hauteur de l obj a l ecran
		//affichage
		ang_strt -= inc;
		i++;
	}
}

//	printf("len_x = [%f] && len_y = [%f]\n", len_x, len_y);
//	printf("AVANT :: ray->len = [%f]\n", ray.len);
//		printf("cam->virtual_h = [%f]\n", cam->virtual_h);
//		printf("APRES :: ray->len = [%f]\n", ray.len);
//		printf("inc = [%f]", inc);
//		printf("ang_strt += inc = [%.15lf]\n", ang_strt);
//		printf("ang_strt = [%d]\n", (int)(DEG(ang_strt)));
