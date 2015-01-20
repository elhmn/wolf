/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/20 17:18:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "check_errors.h"
#include "X.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

/*
** Bug a corriger :: 
** 1- frange forte entre les murs.
** 2- camera rentre dans les murs.
** 3- ajouter une petite map.
*/

/*
** init_wolf
** get_map and put in wolf.map
*/

int		main(int ac, char **av)
{
	t_wolf		wolf;

	if (ac)
	{
		av = av;
		init_wolf(&wolf);
		mlx_key_hook(wolf.env->win, keyrelease_hook, &wolf);
		mlx_hook(wolf.env->win, KeyPress, KeyPressMask, keypress_hook, &wolf);
		mlx_loop_hook(wolf.env->mlx, loop_hook, &wolf);
		mlx_loop(wolf.env->mlx);
	}
	close_mlx(wolf.env);
	return (0);
}
