/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:31:54 by aaparici          #+#    #+#             */
/*   Updated: 2022/02/17 16:31:55 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if_e(!map, errno, ERR_MAP_INIT);
	map->coords_arr = NULL;
	map->width = 0;
	map->height = 0;
	map->z_min = 0;
	map->z_max = 0;
	map->map_color = false;
	map->colors_arr = NULL;
	return (map);
}

t_camera	cam_init(void)
{
	t_camera	cam;

	cam.alpha = 0.0;
	cam.beta = 0.0;
	cam.eta = 0.0;
	cam.x_offset = 0;
	cam.y_offset = 0;
	cam.flyofview = false;
	return (cam);
}

t_fdf	*init(void)
{
	t_fdf	*f;

	f = NULL;
	f = (t_fdf *)malloc(sizeof(t_fdf));
	if_e(!f, errno, "");
	f->mlx.ptr = mlx_init();
	if_e(!f->mlx.ptr, errno, "");
	f->map = map_init();
	f->floor = map_init();
	f->cam = cam_init();
	f->palettes = palettes();
	f->grad = palettes_to_arr(f->palettes);
	f->grad_size = grad_size(f->palettes);
	f->mouse = mouse_init();
	f->resolution = 0;
	f->win.x = WIDTH_0;
	f->win.y = HEIGHT_0;
	f->win.ptr = NULL;
	return (f);
}

int	main(int argc, char **argv)
{
	t_fdf		*f;
	int			fd;
	t_coord_val	*coords_stack;

	f = NULL;
	if_e(argc != 2, errno, ERR_USAGE);
	f = init();
	fd = open(argv[1], O_RDONLY);
	if_e(fd < 0, errno, ERR_MAP);
	if_e(read_map(fd, &coords_stack, f) == -1, errno, ERR_MAP_READING);
	close(fd);
	get_map(&coords_stack, f);
	resolution(f);
	zoom_init(f);
	draw(f);
	mlx_loop(f->mlx.ptr);
	return (0);
}
