/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 23:31:32 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/20 17:14:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "X.h"
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"
#include "libft.h"
#include "check_errors.h"

static void		move_cam_v(int vel, t_cam *cam)
{
	if (cam->direction >= 0. && cam->direction <= M_PI)
		cam->pos.y -= vel * sin(mes_ang(cam->direction));
	else
		cam->pos.y += vel * sin(mes_ang(cam->direction));
	if (cam->direction >= M_PI / 2. && cam->direction <= (3. * M_PI) / 2.)
		cam->pos.x -= vel * cos(mes_ang(cam->direction));
	else
		cam->pos.x += vel * cos(mes_ang(cam->direction));
}

static void		move_cam_h(float vel, t_cam *cam)
{
	cam->direction += vel;
	if (vel < 0)
	{
		if (cam->direction < 0.)
			cam->direction = mes_princ(cam->direction);
	}
	else
	{
		if (cam->direction > 2. * M_PI)
			cam->direction = mes_princ(cam->direction);
	}
}

int				keyrelease_hook(int key, void *param)
{
	t_wolf		*wolf;

	if (param)
	{
		wolf = (t_wolf*)param;
		if (key == LEFT || key == RIGHT)
			wolf->vel_h_bool = 0;
		if (key == UP || key == DOWN)
			wolf->vel_v_bool = 0;
	}
	return (1);
}

int				expose_hook(void *param)
{
	char	*tmp;

	tmp = (char*)param;
	tmp = tmp;
	return (0);
}

int				loop_hook(void *param)
{
	t_wolf	*wolf;
	int		x;
	int		y;
	int		tmpx;
	int		tmpy;

	if (param)
	{
		wolf = (t_wolf*)param;
		tmpx = wolf->cam->pos.x;
		tmpy = wolf->cam->pos.y;
		if (wolf->vel_v_bool)
			move_cam_v(wolf->vel_v, wolf->cam);
		if (wolf->vel_h_bool)
			move_cam_h(wolf->vel_h, wolf->cam);
		x = wolf->cam->pos.x / WALL_W;
		y = wolf->cam->pos.y / WALL_H;
		if (wolf->map[y][x] == WALL)
		{
			wolf->cam->pos.x = tmpx;
			wolf->cam->pos.y = tmpy;
		}
		else
			(wolf->map)[y][x] = VOID;
		raycaster(wolf, wolf->cam, wolf->map);
	}
	return (0);
}
