/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:43:06 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 16:45:45 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (game->player.tile)
		animation(&game->player.character);
	animation(&game->enemy.character);
	animation(&game->items_imgs.block);
	render(*game);
	return (1);
}
