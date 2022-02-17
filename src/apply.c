/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:31:35 by aaparici          #+#    #+#             */
/*   Updated: 2022/02/17 16:31:36 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	apply_brightness(t_rgb c, double brightness)
{
	t_rgb	rgb;

	(brightness > 1.0) && (brightness = 1.0);
	rgb.r = c.r * brightness;
	rgb.g = c.g * brightness;
	rgb.b = c.b * brightness;
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

t_pt	apply_color(int x, int y, t_fdf *f)
{
	t_pt	p;
	t_rgb	*rgb;
	int		idx;

	idx = abs(y * f->map->width + x);
	p.x = x;
	p.y = y;
	p.z = f->map->coords_arr[idx] * f->cam.z_zoom;
	if (f->map->map_color)
		int_to_rgb(&p.rgb, f->map->colors_arr[idx]);
	else
	{
		rgb = (t_rgb *)f->grad[get_color_index(p.z, f->grad_size)];
		p.rgb = *rgb;
	}
	return (p);
}

void	**palettes_to_arr(t_grad *grad)
{
	void	**grad_arr;
	int		i;

	i = grad_size(grad);
	grad_arr = (void **) malloc(sizeof(t_grad) * grad_size(grad));
	if_e(!grad_arr, errno, "");
	grad_arr[i] = NULL;
	while (i--)
	{
		grad_arr[i] = grad;
		grad = grad->next;
	}
	return (grad_arr);
}
