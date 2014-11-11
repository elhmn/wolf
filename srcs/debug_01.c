/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:49:07 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/10 20:27:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf3d.h"

void	print_ray(t_ray *ray)
{
	ft_putendl("\nDEBUG    :: ray");
	ft_putstr("ray->len = [");
	ft_putnbr((t_uint)ray->len);
	ft_putendl("]");
	ft_putstr("ray->virtual_len = [");
	ft_putnbr((t_uint)ray->v_len);
	ft_putendl("]");
	ft_putstr("ray->direction = [");
	ft_putnbr((t_uint)ray->direction);
	ft_putendl("]\n");
}

void	print_screen(t_screen *screen)
{
	if (screen)
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
}

void	print_cam(t_cam *cam)
{
	if (cam)
	{
		ft_putendl("\nDEBUG  :: screen");
		ft_putstr("cam->direction = [");
		ft_putnbr((t_uint)cam->direction);
		ft_putendl("]");
		ft_putstr("cam->champs = [");
		ft_putnbr((t_uint)cam->champs);
		ft_putendl("]");
		ft_putstr("cam->pos.x = [");
		ft_putnbr(cam->pos.x);
		ft_putstr("] && ");
		ft_putstr("cam->pos.y = [");
		ft_putnbr(cam->pos.y);
		ft_putendl("]");
		ft_putstr("cam->dist_proj = [");
		ft_putnbr((t_uint)cam->dist_proj);
		ft_putendl("]");
		ft_putstr("cam->h_cam = [");
		ft_putnbr(cam->h_cam);
		ft_putendl("]\n");
	}
}

void	print_obj(t_obj *obj)
{
	if (obj)
	{
		ft_putendl("\nDEBUG   :: obj");
		ft_putstr("obj->h = [");
		ft_putnbr(obj->h);
		ft_putstr("] && ");
		ft_putstr("obj->w = [");
		ft_putnbr(obj->w);
		ft_putendl("]");
		ft_putstr("obj->type = [");
		ft_putnbr(obj->type);
		ft_putendl("]");
		ft_putstr("obj->text = [");
		ft_putnbr(obj->text);
		ft_putendl("]\n");
	}
}
