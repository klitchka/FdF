#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ld;
	size_t	ls;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (ld >= dstsize)
		return (dstsize + ls);
	i = -1;
	while (++i < ls && i < dstsize - ld - 1)
		dst[ld + i] = src[i];
	dst[ld + i] = '\0';
	return (ld + ls);
}
