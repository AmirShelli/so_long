#include "../../inc/so_long.h"

t_tile	**map_init(char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	// if (!valid_map(map))
	// {
	// 	ft_free_table(map);
	// 	return (NULL);
	// }
	tilemap = generate_tilemap(map, game);
	ft_free_table(map);
	return (tilemap);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y,
			"so_long");
	// mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	// game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	// game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

static void	anim_setup(t_game *game) //what's this for? frames?
{
	game->player.idle_frames = 17;
	game->block_imgs.block_anim = 9;
	// game->enemy_imgs.enemy_anim = 16;
}

int	start(t_game *game, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argv, game);
	if (game->tilemap == NULL)
		return (0);
	game->og_collects = game->collects;
	anim_setup(game);
	game_init(game);
	return (1);
}
