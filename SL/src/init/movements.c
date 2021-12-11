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

// replace dead_img
void	move_to_enemy(t_game *game, t_tile *tile)
{
	game->player.tile = NULL;
	game->player.character.framecount = 0;
	while(game->player.character.framecount <= game->player.character.frames * 3)
	{
		if(game->player.character.framecount == game->player.character.frames/2)
			mlx_put_image_to_window(game->mlx, game->window,
				game->player.dead_img[0], tile->coordinates.x, tile->coordinates.y);
		if(game->player.character.framecount == game->player.character.frames)
			mlx_put_image_to_window(game->mlx, game->window,
				game->player.dead_img[1], tile->coordinates.x, tile->coordinates.y);
		if(game->player.character.framecount == game->player.character.frames * 2)
			mlx_put_image_to_window(game->mlx, game->window,
				game->player.dead_img[2], tile->coordinates.x, tile->coordinates.y);
		game->player.character.framecount++;
	}
	game->player.character.current_img = game->player.dead_img[3];
}
