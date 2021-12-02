#include "../inc/so_long.h"

int main(int argc, char *argv[])
{
	t_game game;

	if(argc == 3) //check is_valid_map
	{
		if (!start(&game, argc, argv))
			return (1);
		// mlx_hook(game.window, 2, 0, input, (void *)&game);
		// mlx_loop_hook(game.mlx, update, (void *)&game);
		mlx_loop(game.mlx);
		return (0);
	}
	// int	error("no valid map, no game.");
	return (1);
}
