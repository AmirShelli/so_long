#include "../../inc/so_long.h"

static void	player_animation(t_player *player)
{
	if (player->framecount == player->idle_frames)
		player->current_img = player->idle_img_0;
	if (player->framecount == player->idle_frames * 2)
		player->current_img = player->idle_img_1;
	if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_2;
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	block_animation(t_block_img *block)
{
	if (block->framecount == block->block_anim)
		block->current_img = block->img_0;
	if (block->framecount == block->block_anim * 2)
		block->current_img = block->img_1;
	if (block->framecount >= block->block_anim * 2)
	{
		block->current_img = block->img_2;
		block->framecount = 0;
	}
	block->framecount += 1;
}

int	update(t_game *game)
{
	player_animation(&game->player);
	block_animation(&game->block_imgs);
	// effect_animation(&game->effect);
	// enemy_animation(&game->enemy_imgs);
	render(*game);
	return (1);
}