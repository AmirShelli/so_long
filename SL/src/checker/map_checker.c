/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:32:09 by bharghaz          #+#    #+#             */
/*   Updated: 2021/12/15 16:32:19 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

int	valid_char(char c);
int	valid_uniquechar(char c, char checker, int *bool);
int	valid_border(char c, t_coord point, t_coord size);

int	valid_file(int argc, char *file)
{
	int	file_length;

	file_length = ft_strlen(file);
	if (argc == 1)
		return (error("no args"));
	if (argc > 2)
		print_warning("only the first file would be used");
	if (file_length >= 4 && !ft_strstr(&file[file_length] - 4, ".ber"))
		return (error("map should be a .ber file"));
	return (1);
}

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
				return (0);
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		valid = error("there must be one 'P' and 'E', and at least one 'C'");
	return (valid);
}
