#include "../../inc/so_long.h"

// void	kill_player(t_game *game, t_coord pos)
// {
// 	game->player.tile = NULL;
// 	effect_anim(&game->effect, pos);
// 	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
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

// void	free_enemies(t_game *game)
// {
// 	t_enemy	*next;

// 	if (game->enemy_list == NULL)
// 		return ;
// 	while (TRUE)
// 	{
// 		next = game->enemy_list->next;
// 		free (game->enemy_list);
// 		if (next == NULL)
// 			break ;
// 		game->enemy_list = next;
// 	}
// }

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	// free_enemies(game);
	// game->enemy_list = NULL;
	exit(0);
}