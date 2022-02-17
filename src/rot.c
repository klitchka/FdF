#include "fdf.h"

void	rot_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rot_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rot_z(int *x, int *y, double eta)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(eta) - previous_y * sin(eta);
	*y = previous_x * sin(eta) + previous_y * cos(eta);
}

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos((30 * M_PI / 180));
	*y = (previous_x + previous_y) * sin((30 * M_PI / 180)) - z;
}

t_pt	project(t_pt p, t_fdf *f)
{
	p.x *= f->cam.zoom;
	p.y *= f->cam.zoom;
	p.x -= (f->map->width * f->cam.zoom) / 2;
	p.y -= (f->map->height * f->cam.zoom) / 2;
	rot_x(&p.y, &p.z, f->cam.alpha);
	rot_y(&p.x, &p.z, f->cam.beta);
	rot_z(&p.x, &p.y, f->cam.eta);
	if (!f->cam.flyofview)
		iso(&p.x, &p.y, p.z);
	p.x += (f->win.x / 2) + f->cam.x_offset;
	p.y += (f->win.y / 2) + f->cam.y_offset;
	return (p);
}
