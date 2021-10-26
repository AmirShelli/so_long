#include "../inc/so_long.h"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	void *mlx = mlx_init();

	//opening a window
	// void *mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// (void) mlx_win;
	// mlx_loop(mlx); //why do we open mlx if the pointer to the window is in mlx_win?

	//init an image
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}