/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_character_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:36:43 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 16:40:12 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	open_player_imgs(t_game *game)
{
	game->player.character.img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/p_img_0.xpm", &game->img_size.x, &game->img_size.y);
	game->player.character.img[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/p_img_1.xpm", &game->img_size.x, &game->img_size.y);
	game->player.character.img[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/player/p_img_2.xpm", &game->img_size.x, &game->img_size.y);
	game->player.dead_img = mlx_xpm_file_to_image(game->mlx,
			"assets/player/d_img_0.xpm", &game->img_size.x, &game->img_size.y);
	game->player.character.current_img = game->player.character.img[0];
}

void	open_enemy_imgs(t_game *game)
{
	game->enemy.character.img[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy/n_img_0.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy.character.img[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy/n_img_1.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy.character.img[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy/n_img_2.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy.character.current_img = game->enemy.character.img[0];
}
