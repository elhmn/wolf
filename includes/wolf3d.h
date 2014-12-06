/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:08:49 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/06 12:05:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>

# define	CHAMPS		M_PI / 3.0
# define	WALL_H		192
# define	WALL_W		192
# define	MAP_H		42
# define	MAP_W		40
# define	START_DIR	0.
# define	HEIGH		480
# define	WIDTH		768
# define	VEL_V		10

# define	UP			65362
# define	DOWN		65364
# define	RIGHT		65363
# define	LEFT		65361

# define	ESCAPE		65307
# define	DEG(x)		(x * 180.0) / M_PI
# define	RAD(x)		(x * M_PI) / 180.0
# define	ABS(x)		(x < 0) ? -x : x

# define	MASK_R		0xFF0000
# define	MASK_G		0x00FF00
# define	MASK_B		0x0000FF

# define	COL_N		0xE37023//0xE89B18
# define	COL_S		0xB24300//0xE83718
# define	COL_E		0xE89B18
# define	COL_O		0xFFD21B
# define	COL_SKY		0x100AC4//0xFFD21B
# define	COL_GD		0xD47408//0x100AC4//0x007482

# define	U_LONG		5
# define	G_LIGHT		1

typedef int	t_uint;

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
	t_uint		bpp;
	t_uint		line;
	t_uint		endian;
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
	void	*img;
}				t_env;


typedef struct		s_ray
{
	float			len;
	float			v_len;
	unsigned int	col_h;
	unsigned int	col_v;
	float			direction;
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
	float			direction;
	float			champs;
	t_pos			pos;
	t_uint			dist_proj;
	t_uint			h_cam;
	t_uint			i;
	t_uint			j;
	float			virtual_h;
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
 ** structure de stockage de couleur
 **
*/

typedef struct			s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}						t_color;

/*
 ** game
 */

typedef	struct	s_wolf
{
	t_screen	*screen;
	t_cam		*cam;
	t_env		*env;
	char		**map;
	t_obj		*wall;
	float		vel_h;
	float		vel_v;
	int			vel_h_bool;
	int			vel_v_bool;
	int			shad;
	int			i_shad;
	int			i_light;
	t_color		*col_sky;
	t_color		*col_gd;
	t_color		*col_wl;
}				t_wolf;

/*
 ** init_var_01.c
*/

void		new_lay(t_env *env, t_lay *lay, t_uint depht);
void		close_mlx(t_env *env);
t_cam		*init_cam(t_cam *cam);
t_env		*init_env(t_env *env);
t_screen	*init_screen(t_screen *screen);

/*
 ** init_var_02.c
*/

t_obj	*init_wall(t_obj *wall);
void	init_ray(t_ray *ray, float direction);
t_color	*init_color(t_color *color, unsigned int col);
t_wolf	*init_wolf(t_wolf *wolf);

/*
 ** color.c
*/

void	set_color(t_color *col);
unsigned int	RGB_to_color(unsigned int r, unsigned int g, unsigned int b);
void	low_light(t_color *color, unsigned int inc, int sign);

/*
 ** debug_01.c
*/

void	print_ray(t_ray *ray);
void	print_obj(t_obj *obj);
void	print_cam(t_cam *cam);
void	print_screen(t_screen *screen);
void	print_color(t_color *color);

/*
** raycaster.c
*/

void	raycaster(t_wolf *wolf, t_cam *cam, char **map);
float	mes_princ(float ang);
void		darkness(t_wolf *wolf);

/*
 ** ray_len.c
 */

float	inter_hor(t_cam *cam, t_ray *ray, char **map);
float	inter_vert(t_cam *cam, t_ray *ray, char **map);
void	map_pos_hor(t_cam *cam, t_ray *ray, t_pos *pos, t_uint h);
void	map_pos_vert(t_cam *cam, t_ray *ray, t_pos *pos, t_uint w);
float	mes_ang(float ang);

/*
 ** draw.c
 */

//void	pixel_put_img(void *img, int x, int y, t_color *col, t_lay lay);

void	draw(t_env *env, t_cam *cam);
void	draw_img(t_wolf *wolf, t_cam *cam);

/*
 ** get_map.c + fonction a coder :: ........................
 */

char	**get_map(void);
void	print_map(char **map);

/*
 ** event_handle.c
 */

int		loop_hook(void *param);
int		expose_hook(void *param);
int		keypress_hook(int key, void *param);
int		keyrelease_hook(int key, void *param);

#endif
