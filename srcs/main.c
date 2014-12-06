/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/06 11:51:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "X.h"
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"
#include "libft.h"
#include "check_errors.h"

/*
** 	A Revoir et a modifier ::
**
**		0- Correction bug color mur mis cote a cote
**		1- Amelioration du de placement.									DONE
**		2- Affiner le trace des surfaces.
**		3- Coloration en fonction de l'orientation							DONE
**		4- Diminution de la luminosite en fonction de la distance			DONE
**		5- Effect de reflection
**		6- gestion de l'expose et optimisation du trace
**		7- collision mur != cam
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
		/*
		mlx_expose_hook(env.win, expose_hook, &env);
		*/
		mlx_key_hook(wolf.env->win, keyrelease_hook, &wolf);
		mlx_hook(wolf.env->win, KeyPress, KeyPressMask, keypress_hook, &wolf);
		mlx_loop_hook(wolf.env->mlx, loop_hook, &wolf);
		mlx_loop(wolf.env->mlx);
	}
	close_mlx(wolf.env);
	/*free_wolf*/
	return (0);
}
