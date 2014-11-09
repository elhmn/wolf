/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 22:49:38 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/09 19:28:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"

void	init_ray(t_ray *ray, float direction)
{
	ray->len = 0;
	ray->virtual_len = 0;
	ray->direction = (direction >= 2. * M_PI) ? direction / (2. * M_PI) : direction;
//	printf("ray->direction = [%lf]\n", DEG(ray->direction));
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
