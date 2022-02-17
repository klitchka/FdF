#include "fdf.h"

t_coord_val	*pop(t_coord_val **coords_stack)
{
	t_coord_val	*top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}

void	get_map(t_coord_val **coords_stack, t_fdf *f)
{
	t_coord_val	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = f->map->width * f->map->height * sizeof(int);
	f->map->coords_arr = (int *)malloc(arr_size);
	if_e(!f->map->coords_arr, errno, ERR_CONV_TO_ARR);
	f->map->colors_arr = (int *)malloc(arr_size);
	if_e(!f->map->colors_arr, errno, ERR_CONV_TO_ARR);
	i = f->map->width * f->map->height - 1;
	while (i >= 0)
	{
		coord = pop(coords_stack);
		f->map->coords_arr[i] = coord->z;
		f->map->colors_arr[i] = coord->rgb;
		if (coord->z > f->map->z_max)
			f->map->z_max = coord->z;
		if (coord->z < f->map->z_min)
			f->map->z_min = coord->z;
		i--;
		free(coord);
	}
}
