#include "fdf.h"

float	get_incr(t_fdf *f, int dx, int dy, double *zoom_max_min)
{
	float	incr;
	int		height;
	int		width;
	double	zoom;

	width = f->win.x;
	height = f->win.y;
	zoom = zoom_max_min[0];
	incr = 0.0;
	if (dx < (width / D_MAX) && dy < (height / D_MAX))
	{
		while ((zoom + incr) < zoom_max_min[1]
			 && (((dx / zoom) * (zoom + incr)) < width / D_MIN)
			 && ((dy / zoom) * (zoom + incr)) < height / D_MIN)
			incr += 0.5;
	}
	else if (dx > (width / D_MIN) || dy > (height / D_MIN))
	{
		while ((zoom + incr) > zoom_max_min[2]
			&& (((dx / zoom) * (zoom + incr)) > width / D_MIN
				|| ((dy / zoom) * (zoom + incr)) > height / D_MIN))
			incr -= 0.5;
	}
	return (incr);
}

void	zoom_init(t_fdf *f)
{
	f->cam.zoom = 40.0;
	f->cam.z_zoom = 10.0;
	f->cam.zoom_accel = 0.2;
	f->cam.z_accel = 0.2;
	f->cam.zoom += get_incr(f, f->map->width, f->map->height,
			(double [3]){f->cam.zoom, 60.0, 1.8});
	f->cam.z_zoom += get_incr(f, f->map->z_max - f->map->z_min,
			f->map->z_max - f->map->z_min,
			(double [3]){f->cam.z_zoom, 30.0, 0.8});
}
