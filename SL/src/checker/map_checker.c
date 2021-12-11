#include "../../inc/map.h"

int	valid_char(char c);
int	valid_uniquechar(char c, char checker, int *bool);
int	valid_border(char c, t_coord point, t_coord size);

/* Returns 1 if the file is valid */
int	valid_file(int argc, char *file)
{
	(void) file;
	if (argc == 1)
		return (error("no args"));
	if (argc > 2)
		print_warning("only the first file would be used");
	// if (!ft_strend_cmp(file, ".ber"))
	// 	return (error("map should be a .ber file"));
	return (1);
}

/* Initialize the data needed to check if the map is valid */
static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_table_linecount(map);
	data.b_player = 0;
	data.b_exit = 0;
	data.b_collect = 0;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

/* Checks to do to each indivial tile of the map.
* When it founds one, pritns an error and returns 0. */
static int	checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
		return (error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->b_exit = 1;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
		data->b_collect = 1;
	return (1);
}

/* Returns 1 if the map is valid.
* Printing an error message and returning 0 if not */
int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	int					valid;

	data = init_checkerdata(map);
	valid = 1;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != (size_t)data.size.x)
			valid = error("map must be rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == 0)
				valid = 0;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		valid = error("there must be one 'P' and 'E', and at least one 'C'");
	return (valid);
}
