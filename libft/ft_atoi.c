#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned long	acc;
	int				sign;

	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	sign = 1;
	if (*s == '-')
		sign = -1;
	if ((*s == '-') || (*s == '+'))
		s++;
	acc = 0;
	while (ft_isdigit(*s))
	{
		if (acc >= LONG_MAX / 10)
		{
			if (sign < 0 )
				return (sign * LONG_MIN);
			else
				return (sign * LONG_MAX);
		}
		else
			acc = acc * 10 + *s - '0';
		s++;
	}
	return (sign * acc);
}
