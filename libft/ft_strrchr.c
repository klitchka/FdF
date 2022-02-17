#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r;
	const char	*p;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	r = NULL;
	p = ft_strchr(s, c);
	while (p != NULL)
	{
		r = p;
		s = p + 1;
		p = ft_strchr(s, c);
	}
	return ((char *)r);
}
