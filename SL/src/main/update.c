#include "../../inc/so_long.h"

static void	animation(t_animated *object)
{
	if (object->framecount == object->frames)
		object->current_img = object->img[0];
	if (object->framecount == object->frames * 2)
		object->current_img = object->img[1];
	if (object->framecount >= object->frames * 3)
	{
		object->current_img = object->img[2];
		object->framecount = 0;
	}
	object->framecount += 1;
}

int	update(t_game *game)
{
	if(game->player.tile)
		animation(&game->player.character); 
	animation(&game->enemy.character);
	animation(&game->items_imgs.block);
	render(*game); 
	return (1);
}