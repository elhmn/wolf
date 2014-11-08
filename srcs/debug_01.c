/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:49:07 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/08 22:54:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf3d.h"

void	print_screen(t_screen *screen)
{
	ft_putendl("\nDEBUG  :: cam");
	ft_putstr("screen->h = [");
	ft_putnbr(screen->h);
	ft_putendl("]");
	ft_putstr("screen->w = [");
	ft_putnbr(screen->w);
	ft_putendl("]");
	ft_putstr("screen->center.pos.x = [");
	ft_putnbr(screen->center.x);
	ft_putstr("] && ");
	ft_putstr("screen->center.pos.y = [");
	ft_putnbr(screen->center.y);
	ft_putendl("]\n");
}

void	print_cam(t_cam *cam)
{
	if (cam)
	{
		ft_putendl("\nDEBUG  :: screen");
		ft_putstr("cam->direction = [");
		ft_putnbr(cam->direction);
		ft_putendl("]");
		ft_putstr("cam->angle = [");
		ft_putnbr(cam->angle);
		ft_putendl("]");
		ft_putstr("cam->pos.x = [");
		ft_putnbr(cam->pos.x);
		ft_putstr("] && ");
		ft_putstr("cam->pos.y = [");
		ft_putnbr(cam->pos.y);
		ft_putendl("]");
		ft_putstr("cam->dist_proj = [");
		ft_putnbr(cam->dist_proj);
		ft_putendl("]");
		ft_putstr("cam->h_cam = [");
		ft_putnbr(cam->h_cam);
		ft_putendl("]\n");
	}
}
