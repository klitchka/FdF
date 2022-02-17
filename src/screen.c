#include "fdf.h"

void	clear_window(t_fdf *f)
{
	if (f->win.ptr)
	{
		mlx_clear_window(f->mlx.ptr, f->win.ptr);
		mlx_destroy_image(f->mlx.ptr, f->img.ptr);
		mlx_destroy_window(f->mlx.ptr, f->win.ptr);
	}
}

void	new_window(t_fdf *f)
{
	int		endian;

	f->win.ptr = mlx_new_window(f->mlx.ptr, f->win.x, f->win.y, "FdF");
	if_e(!f->win.ptr, errno, "");
	f->img.ptr = mlx_new_image(f->mlx.ptr, f->win.x, f->win.y);
	if_e(!f->img.ptr, errno, "");
	f->img.addr = mlx_get_data_addr(f->img.ptr,
			 &(f->bits_per_pix), &(f->size_line), &(endian));
	if_e(!f->img.addr, errno, "");
	mlx_hook(f->win.ptr, 2, 0, (int (*)()) handle_key, f);
	mlx_hook(f->win.ptr, 4, 0, (int (*)()) mouse_press, f);
	mlx_hook(f->win.ptr, 5, 0, (int (*)()) mouse_release, f);
	mlx_hook(f->win.ptr, 6, 0, (int (*)()) mouse_move, f);
	mlx_hook(f->win.ptr, 17, 0, (int (*)()) handle_close, f);
}

void	set_window(t_fdf *f, int width, int height)
{
	f->win.x = width;
	f->win.y = height;
	f->resolution++;
	if (f->resolution > 2)
		f->resolution = 0;
	clear_window(f);
	new_window(f);
}

void	resolution(t_fdf *f)
{
	int	x;
	int	y;

	x = f->map->width;
	y = f->map->height;
	if (x <= 200)
	{
		if (y < 100)
			set_window(f, WIDTH_0, HEIGHT_0);
		else if (y >= 100 && y < 190)
			set_window(f, WIDTH_1, HEIGHT_1);
		else if (y >= 190)
			set_window(f, WIDTH_2, HEIGHT_2);
	}
	else
	{
		set_window(f, WIDTH_2, HEIGHT_2);
	}
}
