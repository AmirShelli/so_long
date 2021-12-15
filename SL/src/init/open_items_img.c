/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_items_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:34:45 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 16:40:25 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	open_player_imgs(t_game *game);
void	open_enemy_imgs(t_game *game);

void	open_wallup_imgs(t_game *game)
{
	game->wall_imgs.up_left = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_up_left.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_up.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.up_right = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_up_right.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.right = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_right.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_walldown_imgs(t_game *game)
{
	game->wall_imgs.down_right = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_down_right.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_down.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down_left = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_down_left.xpm",
			&game->img_size.x, &game->img_size.y);
	game->wall_imgs.left = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall_left.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_non_anim_imgs(t_game *game)
{
	game->items_imgs.collects_img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/c_img_0.xpm",
			&game->img_size.x, &game->img_size.y);
	game->items_imgs.collects_img[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/c_img_1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->items_imgs.door_img[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/e_img_1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->items_imgs.door_img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/e_img_0.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_anim_imgs(t_game *game)
{
	game->items_imgs.block.img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/b_img_0.xpm",
			&game->img_size.x, &game->img_size.y);
	game->items_imgs.block.img[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/b_img_1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->items_imgs.block.img[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/items/b_img_2.xpm",
			&game->img_size.x, &game->img_size.y);
	game->items_imgs.block.current_img = game->items_imgs.block.img[0];
	game->wall_imgs.empty = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_wallup_imgs (game);
	open_walldown_imgs (game);
	open_player_imgs(game);
	open_enemy_imgs(game);
	open_non_anim_imgs(game);
	open_anim_imgs(game);
}
