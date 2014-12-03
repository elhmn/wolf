/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/03 21:50:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"
#include "libft.h"
#include "check_errors.h"

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

int		key_hook(int key, void *param)
{
	t_cam		*cam;
	t_wolf		*wolf;

	wolf = (t_wolf*)param;
	cam = (t_cam*)(wolf->cam);
	if (param)
	{
		if (key == ESCAPE)
			exit(0); //QUIT
		if (key == LEFT)
		{
			ft_putendl("left : ");
			cam->direction += 0.1;
			if (cam->direction + (M_PI / 6.) >= 2. * M_PI)
				cam->direction = M_PI / 6.;
		}
		if (key == RIGHT)
		{
			ft_putendl("right : ");
			cam->direction -= 0.1;
			if (cam->direction - (M_PI / 6.) <= 0.)
				cam->direction = 2. * M_PI - (M_PI / 6.);
		}
		if (key == UP)
		{
			ft_putendl("up : ");
			cam->pos.x += 5;
		}
		if (key == DOWN)
		{
			ft_putendl("down : ");
			cam->pos.x -= 5;
		}
//		print_cam(cam);
		print_map(wolf->map);
		raycaster(wolf->env, wolf->cam, wolf->map);
	}
	return (0);
}


int		expose_hook(void *param)
{
	char	*tmp;

	tmp = (char*)param;
	tmp = tmp;
	printf("je suis con\n");
	return (0);
}

int		loop_hook(void *param)
{
	t_wolf	*wolf;

	if (param)
	{
		wolf = (t_wolf*)param;
//		ft_putendl("test loop_hook");
//		ft_putendl("###           ###");
//		print_map(wolf->map);
//		ft_putendl("###           ###");
		(wolf->map)[wolf->cam->pos.y / WALL_H][wolf->cam->pos.x / WALL_W] = CAM;
//		print_map(wolf->map);
//		raycaster(wolf->env, wolf->cam, wolf->map);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env		env;
	t_screen 	screen;
	t_lay		bg_lay;
	t_obj		wall;
	t_cam		cam;
	t_wolf		wolf;
	int			i;

	i = -1;
	char	**map = malloc(sizeof(char*) * 12);
	map[11] = 0;
	while (++i < 11)
		map[i] = ft_strnew(11);
	ft_strcpy(map[0], "1111111111");
	ft_strcpy(map[1], "1000000001");
	ft_strcpy(map[2], "1001000011");
	ft_strcpy(map[3], "1000000111");
	ft_strcpy(map[4], "1000100011");
	ft_strcpy(map[5], "1000000001");
	ft_strcpy(map[6], "1000000011");
	ft_strcpy(map[7], "1000000001");
	ft_strcpy(map[8], "1000000001");
	ft_strcpy(map[9], "1000001001");
	ft_strcpy(map[10], "1111111111");

	init_env(&env);
	new_lay(&env, &bg_lay, 5000);
	init_cam(&cam);
	init_screen(&screen);
	init_wall(&wall);
	print_cam(&cam);
	print_screen(&screen);
	print_obj(&wall);
	wolf.cam = &cam;
	wolf.screen = &screen;
	wolf.env = &env;
	wolf.map = map;
//	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	if (ac)
	{
		av = av;
//	mlx_expose_hook(env.win, expose_hook, &env);
		mlx_key_hook(env.win, key_hook, &wolf);
		mlx_loop_hook(env.mlx, loop_hook, &wolf);
		mlx_loop(env.mlx);
//usleep(60);
	}
//	close_mlx(&env);
	return (0);
}
