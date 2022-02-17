/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:30:57 by aaparici          #+#    #+#             */
/*   Updated: 2022/02/17 16:30:58 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	has_color(const char *s)
{
	if (ft_strchr(s, ','))
		return (true);
	else
		return (false);
}

void	push(t_coord_val **coords_stack, t_coord_val *val)
{
	if (coords_stack)
	{
		if (val)
			val->next = *coords_stack;
		*coords_stack = val;
	}
}

t_coord_val	*new_coord(char *s)
{
	t_coord_val	*coord;
	char		**parts;

	coord = (t_coord_val *)malloc(sizeof(t_coord_val));
	if_e(!coord, errno, ERR_MAP_READING);
	parts = ft_split(s, ',');
	if_e(!parts, errno, ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	if (parts[1])
		coord->rgb = hextoi(parts[1]);
	else
		coord->rgb = -1;
	coord->next = NULL;
	free_arr(parts);
	return (coord);
}

void	push_line(char **coords_line, t_coord_val **coords_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else
		if_e(map->width != width, errno, ERR_MAP);
}

int	read_map(const int fd, t_coord_val **coords_stack, t_fdf *f)
{
	char	*line;
	int		result;
	char	**coords_line;

	result = 1;
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (result > 0)
		{
			coords_line = ft_split(line, ' ');
			if_e(!(coords_line), errno, ERR_MAP_READING);
			if (!(f->map->map_color))
				f->map->map_color = has_color(line);
			push_line(coords_line, coords_stack, f->map);
			free_arr(coords_line);
			free(line);
			if_e(!(*coords_stack), errno, ERR_MAP);
			f->map->height++;
		}
	}
	return (result);
}
