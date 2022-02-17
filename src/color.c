/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:31:39 by aaparici          #+#    #+#             */
/*   Updated: 2022/02/17 16:31:40 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color_index(int z, int size)
{
	int	idx_steps;
	int	mid_idx;

	idx_steps = 1024 / size;
	mid_idx = size / 2;
	if (!idx_steps)
		idx_steps = 1;
	mid_idx += (z / idx_steps);
	if (mid_idx < 0)
		mid_idx = 0;
	if (mid_idx >= size)
		mid_idx = size - 1;
	return (mid_idx);
}

t_rgb	get_color(t_rgb start, t_rgb end, double percent)
{
	t_rgb	c;

	c.r = ((start.r * (1.0 - percent)) + (end.r * percent));
	c.g = ((start.g * (1.0 - percent)) + (end.g * percent));
	c.b = ((start.b * (1.0 - percent)) + (end.b * percent));
	return (c);
}

void	int_to_rgb(t_rgb *rgb, int color)
{
	rgb->r = color / (256 * 256);
	rgb->g = (color / 256) % 256;
	rgb->b = color % 256;
}

void	color_node(t_rgb start, int steps, t_rgb end, t_rgb *rgb)
{
	int	diff;

	diff = abs(start.r - end.r) / (steps);
	if (start.r <= end.r)
		rgb->r += diff;
	else
		rgb->r += -diff;
	diff = abs(start.g - end.g) / (steps);
	if (start.g <= end.g)
		rgb->g += diff;
	else
		rgb->g += -diff;
	diff = abs(start.b - end.b) / (steps);
	if (start.b <= end.b)
		rgb->b += diff;
	else
		rgb->b += -diff;
}

t_grad	*palettes(void)
{
	t_grad	*grad;

	grad = NULL;
	palette(&grad, FDF_TOMATO, 16, FDF_ORANGE_RED);
	palette(&grad, FDF_ORANGE_RED, 16, FDF_CRIMSON);
	palette(&grad, FDF_CRIMSON, 16, FDF_RED);
	palette(&grad, FDF_RED, 16, FDF_DARK_SEA_GREEN);
	palette(&grad, FDF_DARK_SEA_GREEN, 16, FDF_DARK_OLIVE_GREEN);
	palette(&grad, FDF_DARK_OLIVE_GREEN, 16, FDF_TAN);
	palette(&grad, FDF_TAN, 16, FDF_PLUM);
	palette(&grad, FDF_PLUM, 16, FDF_LIGHT_SKY_BLUE);
	palette(&grad, FDF_LIGHT_SKY_BLUE, 16, FDF_YELLOW_GREEN);
	palette(&grad, FDF_YELLOW_GREEN, 16, FDF_GOLD);
	palette(&grad, FDF_GOLD, 16, FDF_WHEAT);
	palette(&grad, FDF_WHEAT, 16, FDF_LIGHT_GRAY);
	return (grad);
}
