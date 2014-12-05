/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:20:32 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/05 08:48:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"
#include <mlx.h>

float	mes_ang(float ang)
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

void	map_pos_vert(t_cam *cam, t_ray *ray, t_pos *pos, t_uint w)
{
	float		h;

	h = sqrt(pow(ray->len, 2) - pow(w, 2));
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
	{
		if (((int)(cam->pos.x - w) % WALL_W) == 0)
			pos->x = -1 + (cam->pos.x - w) / WALL_W;
		else
			pos->x = (cam->pos.x - w) / WALL_W;
	}
	else
		pos->x = (cam->pos.x + w) / WALL_W;
	if (ray->direction >= 0. && ray->direction <= M_PI)
	{
		if (((int)(cam->pos.y - h) % WALL_H) == 0)
			pos->y = -1 + (cam->pos.y - h) / WALL_H;
		else
			pos->y = (cam->pos.y - h) / WALL_H;
	}
	else
		pos->y = (cam->pos.y + h) / WALL_H;
}

float	inter_vert(t_cam *cam, t_ray *ray, char **map)
{
	t_uint	w;
	t_pos	pos;
	float	port_2;

	if ((int)DEG(ray->direction) == (int)DEG(M_PI / 2.)
			|| (int)DEG(ray->direction) == (int)DEG((3. * M_PI) / 2.))
		return (0);
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
		w = cam->pos.x % WALL_W;
	else
		w = WALL_W - (cam->pos.x % WALL_W);
	ray->len = (float)w / cos(mes_ang(ray->direction));
	map_pos_vert(cam, ray, &pos, w);
	port_2 = (float)WALL_W / cos(mes_ang(ray->direction));
	while (!((pos.y > MAP_H || pos.x > MAP_W || pos.x < 0)
				|| (pos.y < 0 || (map[pos.y][pos.x] == '1'))))
	{
		ray->len += port_2;
		w += WALL_W;
		map_pos_vert(cam, ray, &pos, w);
	}
	return (ray->len);
}

void	map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h)
{
	float		w;

	w = sqrt(pow(ray->len, 2) - pow(h, 2));
	if (ray->direction > 0. && ray->direction < M_PI)
	{
		if (((int)(cam->pos.y - h) % WALL_H) == 0)
			pos->y = -1 + (cam->pos.y - h) / WALL_H;
		else
			pos->y = (cam->pos.y - h) / WALL_H;
	}
	else
		pos->y = (cam->pos.y + h) / WALL_H;
	if (ray->direction > M_PI / 2. && ray->direction < (3. * M_PI) / 2.)
	{
		if (((int)(cam->pos.x - w) % WALL_W) == 0)
			pos->x = -1 + (cam->pos.x - w) / WALL_W;
		else
			pos->x = (cam->pos.x - w) / WALL_W;
	}
	else
		pos->x = (cam->pos.x + w) / WALL_W;
}

float	inter_hor(t_cam *cam, t_ray *ray, char **map)
{
	t_uint	h;
	t_pos	pos;
	float	port_2;

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
	while (!((pos.y > MAP_H || pos.x > MAP_W || pos.x < 0)
				|| (pos.y < 0 || (map[pos.y][pos.x] == '1'))))
	{
		ray->len += port_2;
		h += WALL_H;
		map_pos_hor(cam, ray, &pos, h);
	}
	return (ray->len);
}
