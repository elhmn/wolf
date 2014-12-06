/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 06:17:40 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/06 08:05:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
# define MASK_R	0xFF0000
# define MASK_G 0x00FF00
# define MASK_B	0x0000FF
# define COL 0xFF00FF

typedef struct			s_color
{
	unsigned int	col;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}						t_color;

#define WIDTH 400
#define HEIGH 400

void	set_color(t_color *color, unsigned int col)
{
	if (color)
	{
		color->col = col;
		color->r = (MASK_R & col) >> (8 * 2);
		color->g = (MASK_G & col) >> 8;
		color->b = (MASK_B & col);
	}
}

unsigned int	RGB_to_color(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int color;

	color = 0;
	r = (r << 8 * 2);
	g = (g << 8);
	color = r | g | b;
	return (color);
}

void	print_color(t_color *color)
{
	if (color)
	{
		printf("color->col = [%d]\n", color->col);
		printf("color->r = [%d]\n", color->r);
		printf("color->g = [%d]\n", color->g);
		printf("color->b = [%d]\n", color->b);
		printf("color->a = [%d]\n", color->a);
	}
}

void	low_light(t_color *color, unsigned int inc, int sign)
{
	if (color)
	{
		if (sign > 0)
		{
			if (color->r)
				color->r += inc;
			if (color->g)
				color->g += inc;
			if (color->b)
				color->b += inc;
		}
		else
		{
			if (color->r)
				color->r -= inc;
			if (color->g)
				color->g -= inc;
			if (color->b)
				color->b -= inc;
		}
		color->col = RGB_to_color(color->r, color->g, color->b);
	}
}

int		main(void)
{
	void		*mlx;
	void		*win;
	int			i;
	int			j;
	t_color		*color;
	int			sign;

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGH, "TEST");
	color = (t_color*)malloc(sizeof(t_color));
	if (!color)
	{
		printf("erreur\n");
		return (-1);
	}
	set_color(color, COL);
	color->col = RGB_to_color(color->r, color->g, color->b);
	while (i < WIDTH)
	{
		j = 0;
		sign = 1;
		set_color(color, COL);
		while (j < HEIGH)
		{
			low_light(color, 1, sign);
			if (color->col == 0)
				sign = -1;
			mlx_pixel_put(mlx, win, i, j, color->col);
			j++;
		}
		i++;
	}
	free(color);
	mlx_loop(mlx);
	return (0);
}
