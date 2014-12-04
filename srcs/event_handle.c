/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 23:31:32 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/05 00:11:03 by bmbarga          ###   ########.fr       */
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

static void		move_cam(int vel, t_cam *cam)
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

int				key_hook(int key, void *param)
{
	t_wolf		*wolf;

	if (param)
	{
		wolf = (t_wolf*)param;
		if (key == ESCAPE)
			exit(0);
		if (key == LEFT)
		{
			wolf->cam->direction += VEL_H;
			if (wolf->cam->direction > 2. * M_PI)
				wolf->cam->direction = mes_princ(wolf->cam->direction);
		}
		if (key == RIGHT)
		{
			wolf->cam->direction -= VEL_H;
			if (wolf->cam->direction < 0.)
				wolf->cam->direction = mes_princ(wolf->cam->direction);
		}
		if (key == UP)
			move_cam(VEL_V, wolf->cam);
		if (key == DOWN)
			move_cam(-VEL_V, wolf->cam);
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

int		loop_hook(void *param)
{
	t_wolf	*wolf;
	int		x;
	int		y;

	if (param)
	{
		wolf = (t_wolf*)param;
		x =	wolf->cam->pos.x / WALL_W;
		y = wolf->cam->pos.y / WALL_H;
		(wolf->map)[y][x] = VOID;
		raycaster(wolf->env, wolf->cam, wolf->map);
	}
	return (0);
}
