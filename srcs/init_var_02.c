/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 22:49:38 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/09 08:00:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"

void	init_wall(t_obj *wall)
{
	if (!wall)
		if (!(wall = (t_obj*)malloc(sizeof(t_obj))))
			check_errors(MALLOC, "wall", "init_var_02.c");
	if (wall)
	{
		wall->h = WALL_H;
		wall->w = WALL_W;
		wall->type = WALL;
		wall->text = 0;
	}
}
