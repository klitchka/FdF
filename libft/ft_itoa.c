#include "libft.h"

int	num_d(int num)
{
	int				len;
	unsigned int	un;

	len = 0;
	un = num;
	if (num <= 0)
	{
		len = 1;
		un = -num;
	}
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char			*s;
	int				len;
	int				minus;
	int				sign;

	len = num_d(num);
	minus = 0;
	sign = 1;
	if (num < 0)
	{
		minus = 1;
		sign = -1;
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (minus)
		s[0] = '-';
	while (len-- > minus)
	{
		s[len] = '0' + num % 10 * sign;
		num /= 10;
	}
	return (s);
}
