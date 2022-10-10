#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i;
	int j;

	i = 200;
	j = 200;
	(void) j;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (i <= 300 )
	{
		my_mlx_pixel_put(&img, i, 200, 0x0047B9E1);
		my_mlx_pixel_put(&img, i, 300, 0x0047B9E1);
		my_mlx_pixel_put(&img, 200, j, 0x00FF00FF);
		my_mlx_pixel_put(&img, 300, j, 0x00FF00FF);
		i++;
		j++;
	}
	i = 0;
	j = 200;
	while (200 + i < 300 - i)
	{
		// my_mlx_pixel_put(&img, i, 200, 0x0047B9E1);
		my_mlx_pixel_put(&img, 200 + i, j, 0x0047B9E1);
		my_mlx_pixel_put(&img, 300 - i, j, 0x00FF00FF);
		i++;
		j--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
    return 0;
}