#include "../../inc/so_long.h"

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

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/player/p_img_0.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/player/p_img_1.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/player/p_img_2.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.idle_img_0;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/items/c_img_0.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/items/c_img_1.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_door_imgs(t_game *game)
{
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"assets/items/e_img_1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"assets/items/e_img_0.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_block_imgs(t_game *game)
{
	game->block_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/items/b_img_0.xpm",
			&game->img_size.x, &game->img_size.y);
	game->block_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/items/b_img_1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->block_imgs.img_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/items/b_img_2.xpm",
			&game->img_size.x, &game->img_size.y);
	game->block_imgs.current_img = game->block_imgs.img_0;
	
	game->wall_imgs.empty = mlx_xpm_file_to_image(game->mlx,
			"assets/map/wall.xpm",
			&game->img_size.x, &game->img_size.y);
}

// static void	open_enemy_imgs(t_game *game)
// {
// 	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_01.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.basic_02 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_02.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
// 	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_03.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.follow_02 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_04.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
// }

void	open_images(t_game *game)
{
	open_wallup_imgs (game);
	open_walldown_imgs (game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_block_imgs(game);
	open_door_imgs(game);
}
