/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:24:59 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/20 01:11:45 by bmbarga          ###   ########.fr       */
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

static void	pixel_put_img(t_wolf *wolf, int x, int y, t_color *col)
{
	t_uint		size;
	char		*image;

	if (!wolf)
		check_errors(NUL, "wolf", "draw.c");
	image = wolf->img;
	if (col && image)
	{
		size = wolf->lay.line;
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

	lim = (HEIGH - (t_uint)cam->virtual_h) / 2;
	cam->j = lim;
	wolf->img = (char*)wolf->env->img;
	wolf->img = mlx_get_data_addr(wolf->env->img, &(wolf->lay.bpp),
			&(wolf->lay.line), &(wolf->lay.endian));
	ray = ray;
	while (cam->j)
	{
		pixel_put_img(wolf, cam->i, (cam->j)--, wolf->col_sky);
		low_light(wolf->col_sky, (unsigned int)1, 1);
	}
	cam->j = lim;
	while (cam->j < (t_uint)((float)lim + cam->virtual_h))
		pixel_put_img(wolf, cam->i, (cam->j)++, wolf->col_wl);
	while (cam->j < HEIGH)
	{
		pixel_put_img(wolf, cam->i, (cam->j)++, wolf->col_gd);
		low_light(wolf->col_gd, (unsigned int)1, 1);
	}
	(cam->i) += 4;
}
