/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:08:49 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/07 13:42:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

typedef unsigned int	t_uint;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

/*
** s_cam		==> structure of camera
** direction 	==> verteur directeur de la camera
** angle 		==> champs visuel de la camera
** pos 			==> position de la camera sur la map 
** dist_proj 	==> distance de projection
** h_cam		==> hauteur de la camera
*/

typedef struct			s_cam
{
	t_uint			direction;
	t_uint			angle;
	t_pos			pos;
	t_uint			dist_proj;
	t_uint			h_cam;
}						t_cam;

/*
** s_screen		==> structure de l'ecran
** h 			==> hauteur de l'ecran
** w 			==> largeur de l'ecran
** center		==> postion du centre de l ecran 
** dist_proj 	==> distance de projection
*/

typedef struct		s_screen
{
	int				h;
	int				w;
	t_pos			center;
	unsigned int	dist_proj;
}					t_sceen;

/*
** s_wall		==> structure du mur
** h 			==> hauteur du mur
** w 			==> largeur du mur
** type			==> type du mur (bonus)
** text 		==> text du mur
** color		==> coleur du mur
*/

typedef struct		s_wall
{
	t_uint			dist_to_cam;
	t_uint			h;
	t_uint			w;
	t_uint			type;
	t_uint			text;
	t_uint			color;
}					t_wall;


#endif
