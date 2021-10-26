#include "../inc/so_long.h"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	int u;
	void *test = mlx_init();
	void *win = mlx_new_window(test, 1000, 1000, "nu!");
	void *img = mlx_xpm_file_to_image(test, "7e1a45837e29c04a0434148050fbc56a.xpm", &u, &u);
	mlx_put_image_to_window(test, win, img, 0, 0);
	mlx_loop(test);
}