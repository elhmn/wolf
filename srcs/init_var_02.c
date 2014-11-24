/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 22:49:38 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/10 20:33:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"

void	init_ray(t_ray *ray, float dir)
{
	ray->len = 0;
	ray->v_len = 0;
	ray->direction = (dir >= 2. * M_PI) ? dir / (2. * M_PI) : dir;
}

void	init_wall(t_obj *wall)
{
	if (wall)
	{
		wall->h = WALL_H;
		wall->w = WALL_W;
		wall->type = WALL;
		wall->text = 0;
	}
}

void	init_color(t_color	*color)
{
	if (color)
	{
		color->mask_r = 0xFF0000;
		color->mask_g = 0x00FF00;
		color->mask_b = 0x0000FF;
		color->color = 0x0000FF;
	}
}
