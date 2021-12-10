#include "../../inc/so_long.h"

void	remove_player(t_game *game);

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	tile->type = EMPTIED;
	game->collects--;
}

void	move_to_exit(t_game *game)
{
	remove_player(game);
	game->collects = -1;
}

void	move_to_enemy(t_game *game, t_tile *tile)
{
	remove_player(game);
}
