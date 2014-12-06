/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 06:17:40 by bmbarga           #+#    #+#             */
/*   Updated: 2014/12/06 06:19:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
# define MASK_R	0xFF00000
# define MASK_G 0x00FF000
# define MASK_B	0x00000FF

typedef struct	s_color
{
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}				t_color;

#define WIDTH 400
#define HEIGHT 400

int		main(void)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;

	i = 0;
	j = 0;
	return (0);
}
