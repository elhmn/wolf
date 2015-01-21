/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 01:14:00 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/21 04:47:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

static void		aux_press(int key, t_wolf *wolf)
{
	if (key == UP && !wolf->vel_v_bool)
	{
		wolf->vel_v = VEL_V;
		wolf->vel_v_bool = 1;
	}
	if (key == DOWN && !wolf->vel_v_bool)
	{
		wolf->vel_v = -VEL_V;
		wolf->vel_v_bool = 1;
	}
}

int				keypress_hook(int key, void *param)
{
	t_wolf		*wolf;

	if (param)
	{
		wolf = (t_wolf*)param;
		if (key == ESCAPE)
			exit(0);
		if (key == LEFT && !wolf->vel_h_bool)
		{
			wolf->vel_h = 0.02;
			wolf->vel_h_bool = 1;
		}
		if (key == RIGHT && !wolf->vel_h_bool)
		{
			wolf->vel_h = -0.02;
			wolf->vel_h_bool = 1;
		}
		aux_press(key, wolf);
	}
	return (1);
}
