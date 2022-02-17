#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*d;

	uc = (unsigned char)c;
	d = b;
	while (len--)
		*d++ = uc;
	return (b);
}
