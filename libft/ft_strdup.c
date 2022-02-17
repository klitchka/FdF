#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*d;

	len = 0;
	while (str[len])
		len ++;
	len = len + 1;
	d = (char *)malloc(sizeof(char) * len);
	if (d)
		ft_memcpy(d, str, len);
	return (d);
}
