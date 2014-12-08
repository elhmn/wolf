/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 07:42:16 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/08 10:02:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>	/*#####################*/

void	set_color(t_color *col)
{
	if (col)
	{
		col->r = (col->color & MASK_R) >> (8 * 2);
		col->g = (col->color & MASK_G) >> 8;
		col->b = (col->color & MASK_B);
		col->alpha = 0;
	}
}

unsigned int	RGB_to_color(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int color;

	color = 0;
	r = (r << 8 * 2);
	g = (g << 8);
	color = r | g | b;
	return (color);
}

void	low_light(t_color *color, unsigned int inc, int sign)
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
		color->color = RGB_to_color(color->r, color->g, color->b);
	}
}

void	print_color(t_color *color)
{
	if (color)
	{
		printf("color->col = [%d]\n", color->color);
		printf("color->r = [%d]\n", color->r);
		printf("color->g = [%d]\n", color->g);
		printf("color->b = [%d]\n", color->b);
		printf("color->a = [%d]\n", color->alpha);
	}
}
