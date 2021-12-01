#ifndef SO_LONG_H
# define SO_LONG_H
#include "../minilibx/mlx.h"
#include <stdio.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_coord
{
	char			letter;
	int				x;
	int				y;
}				t_coord;

typedef struct s_map
{
	void	*window;
	t_coord	*head;
	int		width;
	int		height;
}				t_map;

#endif