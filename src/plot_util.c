/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:30:09 by aaparici          #+#    #+#             */
/*   Updated: 2022/02/17 16:30:11 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ipart(double x)
{
	return ((int)x);
}

double	fpart(double x)
{
	if (x > 0)
		return (x - ipart(x));
	else
		return (x - (ipart(x) + 1));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}

int	fround(double x)
{
	return (ipart(x + 0.5));
}

void	plot_pixel(t_fdf *f, int x, int y, int rgb)
{
	int	i;

	if (x >= 0 && x < f->win.x && y >= 0 && y < f->win.y)
	{
		i = (x * f->bits_per_pix / 8) + (y * f->size_line);
		f->img.addr[i++] = rgb;
		f->img.addr[i++] = rgb >> 8;
		f->img.addr[i] = rgb >> 16;
	}
}
