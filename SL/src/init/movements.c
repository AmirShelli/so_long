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
	game->player.framecount = 0;
	while(game->player.framecount <= game->player.idle_frames * 3)
	{
		if(game->player.framecount == game->player.idle_frames/2)
			mlx_put_image_to_window(game->mlx, game->window,
				game->player.dead_img[0], tile->coordinates.x, tile->coordinates.y);
		if(game->player.framecount == game->player.idle_frames)
			mlx_put_image_to_window(game->mlx, game->window,
				game->player.dead_img[1], tile->coordinates.x, tile->coordinates.y);
		if(game->player.framecount == game->player.idle_frames * 2)
			mlx_put_image_to_window(game->mlx, game->window,
				game->player.dead_img[2], tile->coordinates.x, tile->coordinates.y);
		game->player.framecount++;
	}
	game->player.current_img = game->player.dead_img[2];
}
