#include "fdf.h"

void	plot_points_x(t_fdf *f, t_var *var, t_pt p0, t_pt p1)
{
	double	percent;
	double	start;

	start = var->xpxl1;
	while (var->xpxl1++ < var->xpxl2)
	{
		if (var->swap)
			percent = curr_percent(var->xpxl2, var->xpxl1, start);
		else
			percent = curr_percent(start, var->xpxl1, var->xpxl2);
		plot_pixel(f, var->xpxl1, ipart(var->intery),
			apply_brightness(get_color(p0.rgb, p1.rgb, percent),
				rfpart(var->intery)));
		plot_pixel(f, var->xpxl1, ipart(var->intery) + 1,
			apply_brightness(get_color(p0.rgb, p1.rgb, percent),
				fpart(var->intery)));
		var->intery += var->gradient;
	}
}

void	plot_points_y(t_fdf *f, t_var *var, t_pt p0, t_pt p1)
{
	double	percent;
	double	start;

	start = var->ypxl1;
	while (var->ypxl1++ < var->ypxl2)
	{
		if (var->swap)
			percent = curr_percent(var->ypxl2, var->ypxl1, start);
		else
			percent = curr_percent(start, var->ypxl1, var->ypxl2);
		plot_pixel(f, ipart(var->interx), var->ypxl1,
			apply_brightness(get_color(p0.rgb, p1.rgb, percent),
				rfpart(var->interx)));
		plot_pixel(f, ipart(var->interx) + 1, var->ypxl1,
			apply_brightness(get_color(p0.rgb, p1.rgb, percent),
				fpart(var->interx)));
		var->interx += var->gradient;
	}
}

void	plot_point_1_2_x(t_fdf *f, t_var *var, t_pt p0, t_pt p1)
{
	var->gradient = var->dy / var->dx;
	var->xend = fround(p0.x);
	var->yend = p0.y + var->gradient * (var->xend - p0.x);
	var->xgap = rfpart(p0.x + 0.5);
	var->xpxl1 = var->xend;
	var->ypxl1 = ipart(var->yend);
	plot_pixel(f, var->xpxl1, var->ypxl1,
		apply_brightness(p0.rgb, rfpart(var->yend) * var->xgap));
	plot_pixel(f, var->xpxl1, var->ypxl1 + 1,
		apply_brightness(p0.rgb, fpart(var->yend) * var->xgap));
	var->intery = var->yend + var->gradient;
	var->xend = fround(p1.x);
	var->yend = p1.y + var->gradient * (var->xend - p1.x);
	var->xgap = fpart(p1.x + 0.5);
	var->xpxl2 = var->xend;
	var->ypxl2 = ipart(var->yend);
	plot_pixel(f, var->xpxl2, var->ypxl2,
		apply_brightness(p1.rgb, rfpart(var->yend) * var->xgap));
	plot_pixel(f, var->xpxl2, var->ypxl2 + 1,
		apply_brightness(p1.rgb, fpart(var->yend) * var->xgap));
	plot_points_x(f, var, p0, p1);
}

void	plot_point_1_2_y(t_fdf *f, t_var *var, t_pt p0, t_pt p1)
{
	var->gradient = var->dx / var->dy;
	var->yend = fround(p0.y);
	var->xend = p0.x + var->gradient * (var->yend - p0.y);
	var->ygap = rfpart(p0.y + 0.5);
	var->ypxl1 = var->yend;
	var->xpxl1 = ipart(var->xend);
	plot_pixel(f, var->xpxl1, var->ypxl1,
		apply_brightness(p0.rgb, rfpart(var->xend) * var->ygap));
	plot_pixel(f, var->xpxl1 + 1, var->ypxl1,
		apply_brightness(p0.rgb, fpart(var->xend) * var->ygap));
	var->interx = var->xend + var->gradient;
	var->yend = fround(p1.y);
	var->xend = p1.x + var->gradient * (var->yend - p1.y);
	var->ygap = fpart(p1.y + 0.5);
	var->ypxl2 = var->yend;
	var->xpxl2 = ipart(var->xend);
	plot_pixel(f, var->xpxl2, var->ypxl2,
		apply_brightness(p1.rgb, rfpart(var->xend) * var->ygap));
	plot_pixel(f, var->xpxl2 + 1, var->ypxl2,
		apply_brightness(p1.rgb, fpart(var->xend) * var->ygap));
	plot_points_y(f, var, p0, p1);
}

void	plot_line(t_fdf *f, t_pt p0, t_pt p1)
{
	t_var	var;

	var.swap = false;
	var.dx = (double)p1.x - (double)p0.x;
	var.dy = (double)p1.y - (double)p0.y;
	if (fabs(var.dx) > fabs(var.dy))
	{
		if (p1.x < p0.x)
		{
			var.swap = true;
			ft_swap(&p0.x, &p1.x);
			ft_swap(&p0.y, &p1.y);
		}
		plot_point_1_2_x(f, &var, p0, p1);
	}
	else
	{
		if (p1.y < p0.y)
		{
			var.swap = true;
			ft_swap(&p0.x, &p1.x);
			ft_swap(&p0.y, &p1.y);
		}
		plot_point_1_2_y(f, &var, p0, p1);
	}
}
