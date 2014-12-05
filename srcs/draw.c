/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:24:59 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/05 08:23:22 by bmbarga          ###   ########.fr       */
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
	t_uint		r;
	t_uint		g;
	t_uint		b;
	t_uint		a;
	t_uint		size;

	if (col && image)
	{
		r = (MASK_R & col->color) >> (8 * 2);
		g = (MASK_G & col->color) >> 8;
		b = (MASK_B & col->color);
		a = col->alpha;
		size = lay.line;
		if (size > 0 && x < WIDTH * 4)
		{
			image[(y * (size)) + x + 0] = b;
			image[(y * (size)) + x + 1] = g;
			image[(y * (size)) + x + 2] = r;
			image[(y * (size)) + x + 3] = a;
		}
	}
}

void		draw_img(t_wolf *wolf, t_cam *cam)
{
	int			lim;
	t_lay		lay;
	char		*image;

	cam->j = 0;
	lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
	image = (char*)wolf->env->img;
	image = mlx_get_data_addr(wolf->env->img, &(lay.bpp), &(lay.line), &(lay.endian));
	while (cam->j < lim)
		pixel_put_img(image, cam->i, (cam->j)++, wolf->col_sky, lay);
	while (cam->j < (t_uint)((float)lim + cam->virtual_h))
		pixel_put_img(image, cam->i, (cam->j)++, wolf->col_wl, lay);
	while (cam->j < HEIGH)
		pixel_put_img(image, cam->i, (cam->j)++, wolf->col_gd, lay);
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
