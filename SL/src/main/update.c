#include "../../inc/so_long.h"

static void	player_animation(t_player *player)
{
	if (player->framecount == player->idle_frames)
	{
		printf("animation %d", player->idle_frames);
		fflush(stdout);
		player->current_img = player->idle_img_0;
	}
	if (player->framecount == player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		printf("animation %d", player->idle_frames);
		fflush(stdout);
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_2;
		player->framecount = 0;
		printf("animation %d", player->idle_frames);
		fflush(stdout);
	}
	player->framecount += 1;
}

int	update(t_game *game)
{
	player_animation(&game->player);
	// collec_animation(&game->collects_imgs);
	// effect_animation(&game->effect);
	// enemy_animation(&game->enemy_imgs);
	render(*game);
	return (1);
}