#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- > 0)
	{
		j = 0;
		while (haystack[j] == needle[j] && j++ <= len)
			if (!needle[j])
				return ((char *)haystack);
		haystack++;
	}
	return (0);
}
