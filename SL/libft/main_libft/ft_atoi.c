#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	while (*str && (ft_isspace(*str)))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str && ft_isdigit(*str) && !(num > 2147483648))
		num = num * 10 + (*str++ - 48);
	if (num > 2147483648)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (sign * num);
}
