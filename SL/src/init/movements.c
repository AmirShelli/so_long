/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:34:36 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 16:34:40 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	move_to_enemy(t_game *game)
{
	game->player.tile = NULL;
	game->player.character.current_img = game->player.dead_img;
}
