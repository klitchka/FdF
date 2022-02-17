#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*sc;

	sc = s;
	while (*sc)
		++sc;
	return ((unsigned int)(sc - s));
}
