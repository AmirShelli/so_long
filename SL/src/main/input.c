#include "../../inc/so_long.h"
#include <stdio.h>

void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game);
void	pick_collect(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

int	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
	{	
		pick_collect(game, tile);
		return (0);
	}
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game);
	else if (tile->type == ENEMY)
	{
		move_to_enemy(game, tile);
		return (0);
	}
	else
		return (0);
	return (1);
}

int	input(int key, t_game *game)
{
	int	moved;
	
	if (key == ESC)
		end_program(game);
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}