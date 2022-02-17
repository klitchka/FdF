#include "libft.h"

size_t	num_chr(const char *s, const char *c)
{
	size_t	numc;

	numc = 0;
	while (ft_strchr(c, *s++) == 0)
		numc++;
	return (numc);
}

int	next_line(char **fdline, char **line, int fd)
{
	char	*tmp_fdline;

	if (!*fdline[fd])
		return (0);
	if (ft_strchr(fdline[fd], '\n'))
	{
		*(fdline[fd] + num_chr(fdline[fd], "\n")) = '\0';
		*line = ft_strdup(fdline[fd]);
		tmp_fdline = ft_strdup(ft_strchr(fdline[fd], '\0') + 1);
		free(fdline[fd]);
		fdline[fd] = ft_strdup(tmp_fdline);
		free(tmp_fdline);
	}
	else
	{
		*line = ft_strdup(fdline[fd]);
		if (fdline[fd])
			ft_memset(fdline[fd], '\0', ft_strlen(fdline[fd]));
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*fdline[MAX_FD];
	int			ret;
	char		*tmp_fdline;

	if (!line || (fd < 0 || fd > MAX_FD) || BUFFER_SIZE < 0)
		return (-1);
	if (!(fdline[fd]))
		fdline[fd] = (char *)malloc(1);
	ret = 1;
	while (!(ft_strchr(fdline[fd], '\n')) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret > 0)
		{
			tmp_fdline = fdline[fd];
			fdline[fd] = ft_strjoin(tmp_fdline, buf);
			free(tmp_fdline);
		}
	}
	return (next_line(fdline, line, fd));
}
