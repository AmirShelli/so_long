#ifndef MAP_H
# define MAP_H

# include "so_long.h"

int		valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);

typedef struct s_mapcheckerdata
{
	t_coord	size;
	t_coord	point;
	int		b_player;
	int		b_exit;
	int		b_collect;
}				t_mapcheckerdata;

#endif
