/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:24:59 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/11 02:30:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"
#include <mlx.h>

void	draw(t_env *env, t_cam *cam)
{
	int		lim;
	
	cam->j = 0;
	lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
	while (cam->j <= lim)
		mlx_pixel_put(env->mlx, env->win, cam->i, (cam->j)++, 0x00FFFF);
	while (cam->j < (t_uint)((float)lim + cam->virtual_h))
		mlx_pixel_put(env->mlx, env->win, cam->i, (cam->j)++, 0xFF00FF);
	while (cam->j < HEIGH)
		mlx_pixel_put(env->mlx, env->win, cam->i, (cam->j)++, 0x00FFFF);
	(cam->i)++;
}
