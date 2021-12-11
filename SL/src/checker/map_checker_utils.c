#include "../../inc/map.h"

/* Returns 1 if <c> is a valid map character */
int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'N')
		return (1);
	return (0);
}

/* Turns <bool> to 1 when <c> is equal to <checker>.
* Returning 0 if <bool> is already 1  */
int	valid_uniquechar(char c, char checker, int *bool)
{
	if (c == checker && *bool == 0)
		*bool = 1;
	else if (c == checker && *bool == 1)
		return (0);
	return (1);
}

/* Returns 0 if <point> is in the border of the map, and <c> is not a '1' */
int	valid_border(char c, t_coord point, t_coord size)
{
	if (point.y == 0 || point.x == 0
		|| point.y == size.y - 1 || point.x == size.x - 1)
		if (c != '1')
			return (0);
	return (1);
}
