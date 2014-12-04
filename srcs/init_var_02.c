/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 22:49:38 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/04 23:19:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"

t_wolf	*init_wolf(t_wolf *wolf)
{
	if (!wolf)
		if (!(malloc(sizeof(t_wolf))))
			check_errors(MALLOC, "wolf", "init_var_02.c");
	wolf->env = init_env(NULL);
	wolf->cam = init_cam(NULL);
	wolf->screen = init_screen(NULL);
	wolf->wall = init_wall(NULL);
	wolf->map = get_map();
	return (wolf);
}

void	init_ray(t_ray *ray, float dir)
{
	ray->len = 0;
	ray->v_len = 0;
	ray->direction = dir;
}

t_obj	*init_wall(t_obj *wall)
{
	if (!wall)
		if (!(wall = malloc(sizeof(t_obj))))
			check_errors(MALLOC, "wall", "init_var_02.c");
	wall->h = WALL_H;
	wall->w = WALL_W;
	wall->type = WALL;
	wall->text = 0;
	return (wall);
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
