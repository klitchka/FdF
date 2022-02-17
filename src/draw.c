/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:31:45 by aaparici          #+#    #+#             */
/*   Updated: 2022/02/17 16:31:45 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw(t_fdf *f)
{
	int	x;
	int	y;

	ft_bzero(f->img.addr, f->win.x * f->win.y * (f->bits_per_pix / 8));
	y = 0;
	while (y < f->map->height)
	{
		x = 0;
		while (x < f->map->width)
		{
			if (x != f->map->width - 1)
				plot_line(f, project(apply_color(x, y, f), f),
					project(apply_color(x + 1, y, f), f));
			if (y != f->map->height - 1)
				plot_line(f, project(apply_color(x, y, f), f),
					project(apply_color(x, y + 1, f), f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->win.ptr, f->img.ptr, 0, 0);
	return (0);
}
