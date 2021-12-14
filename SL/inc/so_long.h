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

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

typedef struct s_coordinates
{
	int				x;
	int				y;
}				t_coord;

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

typedef struct s_animated
{
	void	*current_img;
	int		framecount;
	int		frames;
	void	*img[3];
}			t_animated;

typedef struct s_player
{
	t_tile	*tile;
	t_animated character;
	void	*dead_img;

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

typedef struct s_items_img
{
	t_animated block;
	void	*door_img[2];
	void	*collects_img[2];
}	t_items_img;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_coord			wndw_size;
	t_coord			img_size;
	t_tile			**tilemap;
	int				collects;
	int				moves;

	t_player		enemy;
	t_player		player;
	t_wall_img		wall_imgs;
	t_items_img		items_imgs;
}	t_game;

int		start(t_game *game, char **argv);

int		end_program(t_game *game);
int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);

int		valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);

t_tile	**generate_tilemap(char **map, t_game *game);
void	open_images(t_game *game);

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);
#endif