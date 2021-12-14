#include "../../inc/so_long.h"

static void	animation(t_animated *object)
{
	puts("aye ");
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
	printf("%d \n", object->framecount);
	fflush(stdout);
}

int	update(t_game *game)
{
	if(game->player.tile)
		animation(&game->player.character); 
	animation(&game->enemy.character); 
	puts("\nwe're inside of block anim now.");
	animation(&game->items_imgs.block);
	render(*game); 
	return (1);
}