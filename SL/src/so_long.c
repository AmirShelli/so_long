#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	
	printf("%i\n", keycode);
	return(keycode);
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(keycode);
}

// int	render_next_frame(void *vars)
// {
// 	int i;
// 	int j;
// 	t_data img;

// 	img.img = mlx_new_image(mlx, 670, 400);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	i = 100;
// 	while (i++ < 150)
// 	{
// 		j = 500;
// 		while (j++ < 550)
// 			my_mlx_pixel_put(&img, j, i, 0x00FF0000);
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
// }

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 670, 400, "Hello world!");
	t_data	img;

	//image test//
	// int i;
	// int j;
	// t_data	img;
	// img.img = mlx_new_image(mlx, 670, 400);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// i = 100;
	// while (i++ < 150)
	// {
	// 	j = 500;
	// 	while (j++ < 550)
	// 		my_mlx_pixel_put(&img, j, i, 0x00FF0000);
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
	//X11 masks and hooks//
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_hook(vars.win, 2, 0, key_hook, &vars); //2??? 1L<<0??? what's that for?

	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
