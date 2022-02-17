#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (!d && !s)
		return (NULL);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	return (dst);
}
