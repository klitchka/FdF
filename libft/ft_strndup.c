#include "libft.h"

char	*ft_strndup(const char *s, size_t	len)
{
	char	*d;

	if (len < 0)
		return (0);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (0);
	ft_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}
