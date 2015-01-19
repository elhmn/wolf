/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 07:42:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/20 00:58:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			set_color(t_color *col)
{
	if (col)
	{
		col->r = (col->color & MASK_R) >> (8 * 2);
		col->g = (col->color & MASK_G) >> 8;
		col->b = (col->color & MASK_B);
		col->alpha = 0;
	}
}

t_uint			rgb_to_color(t_uint r, t_uint g, t_uint b)
{
	unsigned int color;

	color = 0;
	r = (r << 8 * 2);
	g = (g << 8);
	color = r | g | b;
	return (color);
}

static void		aux_low_light(t_color *color, t_uint inc)
{
	if ((int)color->r - (int)inc > 0)
		color->r -= inc;
	else
		color->r = 0;
	if ((int)color->g - (int)inc > 0)
		color->g -= inc;
	else
		color->g = 0;
	if (((int)color->b - (int)inc) > 0)
		color->b -= inc;
	else
		color->b = 0;
}

void			low_light(t_color *color, unsigned int inc, int sign)
{
	if (color)
	{
		if (sign > 0)
		{
			if ((int)color->r + (int)inc < 256)
				color->r += inc;
			else
				color->r = 255;
			if ((int)color->g + (int)inc < 256)
				color->g += inc;
			else
				color->g = 255;
			if ((int)color->b + (int)inc < 256)
				color->b += inc;
			else
				color->b = 255;
		}
		else
			aux_low_light(color, inc);
		color->color = rgb_to_color(color->r, color->g, color->b);
	}
}
