/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:33:18 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 16:55:26 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	draw_corner(t_tile tile, t_game game, t_coord pos)
{
	if (tile.coordinates.x == 0
		&& tile.coordinates.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up_left, pos.x, pos.y);
	else if (tile.coordinates.x == 0
		&& tile.coordinates.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down_left, pos.x, pos.y);
	else if (tile.coordinates.x == game.wndw_size.x - IMG_SIZE
		&& tile.coordinates.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up_right, pos.x, pos.y);
	else if (tile.coordinates.x == game.wndw_size.x - IMG_SIZE
		&& tile.coordinates.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down_right, pos.x, pos.y);
	else
		return (0);
	return (1);
}

int	draw_sides(t_tile tile, t_game game, t_coord pos)
{
	if (tile.coordinates.x == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.left, pos.x, pos.y);
	else if (tile.coordinates.x == game.wndw_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.right, pos.x, pos.y);
	else if (tile.coordinates.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up, pos.x, pos.y);
	else if (tile.coordinates.y == game.wndw_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down, pos.x, pos.y);
	else
		return (0);
	return (1);
}

void	draw_wall(t_tile tile, t_game game, t_coord pos)
{	
	if (tile.type == EMPTY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.empty, pos.x, pos.y);
	else if (tile.type == EMPTIED)
		mlx_put_image_to_window(game.mlx, game.window,
			game.items_imgs.collects_img[1], pos.x, pos.y);
	else if (draw_corner(tile, game, pos))
		return ;
	else if (draw_sides(tile, game, pos))
		return ;
	else
		mlx_put_image_to_window(game.mlx, game.window,
			game.items_imgs.block.current_img, pos.x, pos.y);
}
