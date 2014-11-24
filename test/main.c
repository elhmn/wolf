#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

#define WIDTH 500
#define	HEIGHT 500

int		main(void)
{
	void*			mlx;
	void*			win;
	void*			img;
	int				bpp;
	unsigned int	color_value;
	char			*image;
	int				line;
	int				endian;

	int				mask_r = 0xFF0000;
	int				mask_g = 0x00FF00;
	int				mask_b = 0x0000FF;

	int				color = 0x70082f;

	img = NULL;
	win = NULL;
	mlx = NULL;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "42");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	win = win;
	color_value = mlx_get_color_value(mlx, 0xFFFF00);
	printf("color_value = [%d]\n", color_value);
	image = mlx_get_data_addr(img, &bpp, &line, &endian);
	printf("bpp = [%d] && line = [%d] && endian = [%d]\n", bpp, line, endian);
	int		i;
	for (i = 0; i < 20000; i++)
	{
		image[i++] = mlx_get_color_value(mlx, mask_b & color); //bleu
		image[i++] = mlx_get_color_value(mlx, ((mask_g & color) >> 8)); //green
		image[i++] = mlx_get_color_value(mlx, ((mask_r & color) >> (8 * 2))); //red
		image[i] = mlx_get_color_value(mlx, 0x000000); //alpha
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
