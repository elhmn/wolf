/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:24:59 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/07 22:41:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "wolf3d.h"
#include "check_errors.h"
#include <mlx.h>

/*
** set pixel_put_img a 4 parametres
*/

static void	pixel_put_img(char *image, int x, int y, t_color *col, t_lay lay)
{
	t_uint		size;

	if (col && image)
	{
		size = lay.line;
		if (size > 0 && x < WIDTH * 4)
		{
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}

void		draw_img(t_wolf *wolf, t_cam *cam, t_ray ray)
{
	int			lim;
	t_lay		lay;
	char		*image;
//	int			lost_l;

	lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
	cam->j = lim;
	image = (char*)wolf->env->img;
	image = mlx_get_data_addr(wolf->env->img, &(lay.bpp), &(lay.line), &(lay.endian));
	ray = ray;
//	lost_l = (int)((G_LIGHT * (int)(ray.v_len)) / U_LONG);
//	low_light(wolf->col_gd, (unsigned int)lost_l, -1);
	while (cam->j)
	{
		pixel_put_img(image, cam->i, (cam->j)--, wolf->col_sky, lay);
		low_light(wolf->col_sky, (unsigned int)1, 1);
	}
	cam->j = lim;
	while (cam->j < (t_uint)((float)lim + cam->virtual_h))
		pixel_put_img(image, cam->i, (cam->j)++, wolf->col_wl, lay);
	while (cam->j < HEIGH)
	{
		pixel_put_img(image, cam->i, (cam->j)++, wolf->col_gd, lay);
		low_light(wolf->col_gd, (unsigned int)1, 1);
	}
	(cam->i) += 4;
}

void		draw(t_env *env, t_cam *cam)
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
