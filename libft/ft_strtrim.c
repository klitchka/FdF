#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(&s1[i]);
	if (j)
		while (j && ft_strchr(set, s1[i + j - 1]))
			j--;
	r = ft_substr(s1, i, j);
	return (r);
}
