#include "libft.h"

ssize_t	ft_putstr(char const *s)
{
	if (s)
		return (ft_putstr_fd(s, 1));
	return (-1);
}
