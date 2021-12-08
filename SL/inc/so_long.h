#ifndef SO_LONG_H
# define SO_LONG_H
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>

# define IMG_SIZE 32

typedef enum e_tiletype
{
	EMPTY = '0',
	EMPTIED = 'N',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M'
}	t_tiletype;

/* All valid input keys */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

typedef struct s_coordinates
{
	int				x;
	int				y;
}				t_coord;

/* Struct for each tile */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_coord			coordinates;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

/* Info about the player */
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	void	*idle_img_2;
}	t_player;

typedef struct s_wall_img
{
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
	void	*empty;
}	t_wall_img;

typedef struct s_block_img
{
	void	*img_0;
	void	*img_1;
	void	*img_2;
	void	*current_img;
	int 	framecount;
	int		block_anim;
}	t_block_img;

typedef struct s_coll_img
{
	void	*img_0;
	void	*img_1;
}	t_collect_img;

/* All info for the game run */
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_coord			wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_coord			img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_block_img		block_imgs;
	void			*door_open_img;
	void			*door_close_img;
	// t_enemy			*enemy_list;
	// t_enemy_img		enemy_imgs;
}	t_game;

int	start(t_game *game, char **argv);
char	**read_map(char *file);
t_tile	**generate_tilemap(char **map, t_game *game);
void	open_images(t_game *game);

int		end_program(t_game *game);
int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);
int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);
#endif