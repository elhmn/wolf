/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:45:04 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/07 14:51:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h> 

# define HEIGHT 400
# define WIDTH 400

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

void	draw_square(void *mlx, void *win)
{
	int 	s_h;
	int		s_w;
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	int		color = 0xFFFFFF;

	s_h = 100;
	s_w = 150;
	pos_x= WIDTH / 2 - s_w;
	pos_y = HEIGHT / 2 - s_h;
	x = pos_x;
	while (x < pos_x + s_w)
	{
		y = pos_y;
		while (y < pos_y + s_h)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			usleep(100);
			y++;
			color--;
		}
		x++;
	}
}

int		expose_hook(t_env *e)
{
	if (e)
	{
		draw_square(e->mlx, e->win);
		return (0);
	}
	return (-1);
}

int		loop_hook(char *str)
{
	if (str)
	{
//		printf("%s", str);
		return (0);
	}
	return (-1);
}

int		main(int ac, char **av)
{
	t_env	e;

	av = av;
	if (ac)
	{
		e.win = NULL;
		e.mlx = NULL;
		if (!(e.mlx = mlx_init()))
		{
			printf("erreur mlx init\n");
			return (0);
		}
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "je suis con");
		if (!e.win)
		{
			printf("erreur win init\n");
			return (0);
		}
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop_hook(e.mlx, loop_hook, "je suis con\n");
		mlx_loop(e.mlx);
	}
	return (0);
}
