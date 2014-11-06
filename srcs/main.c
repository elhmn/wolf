/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:46:50 by bmbarga           #+#    #+#             */
/*   Updated: 2014/11/06 17:01:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>

# define HEIGHT 400
# define WIDTH 400

int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = NULL;
	win = NULL;
	if (!(mlx = mlx_init()))
	{
		printf("ERROR mlx\n");
		return (-1);
	}
	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, "42")))
	{
		printf("ERROR win\n");
		return (-1);
	}
	mlx_loop(mlx);
	return (0);
}
