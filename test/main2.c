#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>


#define WIDTH 400
#define HEIGHT 400

int		main(void)
{
	void	*win;
	void	*mlx;
	int		color;
	int		i;
	int		j;

	i = 0;
	j = 0;

	color = 0xFFFF00;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "42");
	while (i < 100)
	{
		j = 0;
		while (j < 200)
		{
			mlx_pixel_put(mlx, win, i, j, color);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
