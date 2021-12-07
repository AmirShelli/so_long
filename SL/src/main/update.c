#include "../../inc/so_long.h"

int	update(t_game *game)
{
	// player_animation(&game->player);
	// collec_animation(&game->collects_imgs);
	// effect_animation(&game->effect);
	// enemy_animation(&game->enemy_imgs);
	render(*game);
	return (1);
}