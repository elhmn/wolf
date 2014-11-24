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
#include <unistd.h>
#include "libft.h"
#include "wolf3d.h"
#include "check_errors.h"
#include <mlx.h>


void	pixel_put_img(t_env *env, char *image, int x, int y, t_color *col, t_lay lay)
{
	t_uint		r;
	t_uint		g;
	t_uint		b;
	t_uint		a;
	t_uint		size;

	if (col && image)
	{
		r = (col->mask_r & col->color) >> (8 * 2);
		g = (col->mask_g & col->color) >> 8;
		b = (col->mask_b & col->color);
		a = 0x000000;
		size = lay.line;
		if (size > 0 && x < WIDTH * 4)
		{
			image[(y * (size)) + x + 0] = mlx_get_color_value(env->mlx, b);
			image[(y * (size)) + x + 1] = mlx_get_color_value(env->mlx, g);
			image[(y * (size)) + x + 2] = mlx_get_color_value(env->mlx, r);
			image[(y * (size)) + x + 3] = mlx_get_color_value(env->mlx, a);
		}
	}
}


void	draw_img(t_env *env, t_cam *cam)
{
	int			lim;
	t_color		col;
	t_color		col_lim;
	t_lay		lay;
	char		*image;

	init_color(&col);
	init_color(&col_lim);
	col.color = 0xFF00FF;
	col_lim.color = 0x00FFFF;
	cam->j = 0;
	lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
	image = (char*)env->img;
	image = mlx_get_data_addr(env->img, &(lay.bpp), &(lay.line), &(lay.endian));
	while (cam->j < lim)
		pixel_put_img(env, image, cam->i, (cam->j)++, &col_lim, lay);
	while (cam->j < (t_uint)((float)lim + cam->virtual_h))
		pixel_put_img(env, image, cam->i, (cam->j)++, &col, lay);
	while (cam->j < HEIGH)
		pixel_put_img(env, image, cam->i, (cam->j)++, &col_lim, lay);
	(cam->i) += 4;
}


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

