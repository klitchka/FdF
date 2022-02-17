#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*su;

	uc = c;
	su = (const unsigned char *)s;
	while (n--)
		if (*su++ == uc)
			return ((void *)(su - 1));
	return (NULL);
}
