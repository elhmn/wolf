/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 13:34:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "libft.h"

# define HEIGHT 400
# define WIDTH 400

/*
static char	**map_alloc(t_uint h, t_uint w)
{
	char	**map;
	t_uint	i;

	i = -1;
	map = NULL;
	if (!(map = (char**)malloc(sizeof(char*) * (h + 1))))
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
`
static void	print_map(char map[][11], t_uint h)//, t_uint w)
{
	t_uint	i;
//	t_uint	j;

	i = 0;
//	j = 0;
	while (i < h)
	{
//		j = 0;
//		while (j < w)
//		{
			ft_putendl(map[i]);
//			j++;
//		}
		i++;
	}
}

int		main(int ac, char **av)
{
//	char	**map;
//	map = NULL;
//	map = map_alloc(20, 20);
	char	map[11][11] = { {"1111111111\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1000000001\0"},
							{"1111111111\0"},
							{0}
							};
	av = av;
	print_map(map, 10);
	//if (!map)
//		return (-1);
	if (ac)
	{
		ft_putendl("test");			
	}
	return (0);
}
*/

int		main(int ac, cahr **av)
{
	if (ac)
	{
		av = av;
		ft_putendl("test");
	}
	return (0);
}
