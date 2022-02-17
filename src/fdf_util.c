#include "fdf.h"

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	if_e(bool is_error, int val, char *msg)
{
	if (is_error)
	{
		errno = val;
		if (errno == 0)
			ft_putendl_fd(msg, 2);
		else
			perror(msg);
		exit(EXIT_FAILURE);
	}
}

static int	hexdigit(char c)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < 16)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int	hextoi(const char *str)
{
	size_t			base;
	unsigned long	result;
	size_t			i;

	base = 16;
	i = 2;
	while (str[i])
		result = result * base + hexdigit(str[i++]);
	return ((int)result);
}

double	curr_percent(int start, int curr, int end)
{
	double	here;
	double	distance;
	double	where;

	distance = (double)(end - start);
	where = (double)(curr - start);
	if (distance == 0.0)
		here = 1.0;
	else
		here = where / distance;
	return (here);
}
