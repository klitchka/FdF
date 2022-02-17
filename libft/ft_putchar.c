#include "libft.h"

ssize_t	ft_putchar(char c)
{
	return (ft_putchar_fd(c, 1));
}
