/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:08:49 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/09 09:36:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>

# define	CHAMPS		M_PI / 3.0
# define	WALL_H		64
# define	WALL_W		64
# define	START_DIR	M_PI / 2.0
# define	HEIGH		200
# define	WIDTH		320
# define	DEG(x)		(x * 180.0) / M_PI
# define	RAD(x)		(x * M_PI) / 180.0

typedef unsigned int	t_uint;

enum	e_obj
{
	VOID = 48,
	WALL = 49,
	CAM = 50
};

/*
** layer struct 
** depht		==> layer depht
** img			==>	img
*/

typedef struct		s_lay
{
	void		*img;
	t_uint		depht;
}					t_lay;

typedef struct		s_pos
{
	t_uint				x;
	t_uint				y;
}					t_pos;

/*
** environement variable
*/

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;


typedef struct		s_ray
{
	double			len;
	double			virtual_len;			
	double			direction;
}					t_ray;

/*
** s_cam		==> structure of camera
** direction 	==> verteur directeur de la camera
** champs 		==> champs visuel de la camera
** pos 			==> position de la camera sur la map 
** dist_proj 	==> distance de projection
** h_cam		==> hauteur de la camera
*/

typedef struct			s_cam
{
	double			direction;
	double			champs;
	t_pos			pos;
	t_uint			dist_proj;
	t_uint			h_cam;
}						t_cam;

/*
** s_win		==> structure de l'ecran
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
}					t_screen;

/*
** s_obj		==> structure objet
** h 			==> hauteur objet
** w 			==> largeur objet
** type			==> type de l objet (bonus)
** text 		==> texture de l objet
** color		==> coleur de l'objet (opt) 
*/

typedef struct		s_obj
{
	t_uint			h;
	t_uint			w;
	t_uint			type;
	t_uint			text;
}					t_obj;

/*
** init_var_01.c
*/

void	new_lay(t_env *env, t_lay *lay, t_uint depht);
void	init_cam(t_cam *cam);
void	close_mlx(t_env *env);
void	init_cam(t_cam *cam);
void	init_env(t_env *env);
void	init_screen(t_screen *screen);

/*
** init_var_02.c
*/

void	init_wall(t_obj *wall);
void	init_ray(t_ray *ray, double direction);

/*
** debug_01.c
*/

void	print_ray(t_ray *ray);
void	print_obj(t_obj *obj);
void	print_cam(t_cam *cam);
void	print_screen(t_screen *screen);

/*
** raycaster.c
*/

void	ray_caster(t_env *env, t_cam *cam, char **map);

#endif
