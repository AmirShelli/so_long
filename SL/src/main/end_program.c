#include "../../inc/so_long.h"

// void	kill_player(t_game *game, t_coord pos)
// {
// 	game->player.tile = NULL;
// 	effect_anim(&game->effect, pos);
// }

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	exit(0);
}