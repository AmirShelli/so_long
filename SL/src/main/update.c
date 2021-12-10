#include "../../inc/so_long.h"

static void	player_animation(t_player *player)
{
	if (player->framecount == player->idle_frames)
		player->current_img = player->character_img[0];
	if (player->framecount == player->idle_frames * 2)
		player->current_img = player->character_img[1];
	if (player->framecount >= player->idle_frames * 3)
	{
		player->current_img = player->character_img[2];
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	block_animation(t_items_img *block)
{
	if (block->framecount == block->block_frames)
		block->current_img = block->block_img[0];
	if (block->framecount == block->block_frames * 2)
		block->current_img = block->block_img[1];
	if (block->framecount >= block->block_frames * 2)
	{
		block->current_img = block->block_img[2];
		block->framecount = 0;
	}
	block->framecount += 1;
}

int	update(t_game *game)
{
	if(game->player.tile)
		player_animation(&game->player); 
	player_animation(&game->enemy); 
	block_animation(&game->items_imgs);
	render(*game); 
	return (1);
}