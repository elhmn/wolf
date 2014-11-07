/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/07 13:58:32 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "wolf3D.h"
#include "libft.h"

# define HEIGHT 400
# define WIDTH 400

static char	**map_alloc(u_int h, u_int w)
{
	char	**map;
	int		i;

	i = -1;
	map = NULL;
	if (!(map = (map)malloc(sizeof(*map) * (h + 1))))
	{
		ft_putendl("Error alloc map");
		return (NULL);
	}
	map[h] = 0;
	while (++i < h)
	{
		if (!(map[i] = ft_strnew(w)))
		{
			ft_putendl("Error alloc map[i]");
			return (NULL);
		}
	}
	return (map);
}

int		main(int ac, char **av)
{
	char	**map;

	map = NULL;
	av = av;
	map = map_alloc(20, 20);

	if (ac)
	{
			
	}
	return (0);
}
