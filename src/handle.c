#include "fdf.h"

int	handle_close(t_fdf *f)
{
	mlx_destroy_window(f->mlx.ptr, f->win.ptr);
	free(f->map->colors_arr);
	free(f->map->coords_arr);
	free(f->map);
	free_palette(f->palettes);
	free(f->grad);
	free(f->mlx.ptr);
	system("leaks fdf");
	exit(0);
}

void	handle_key3(int key, t_fdf *f)
{
	if (key == KEY_A)
	{
		if (f->resolution == 2)
			set_window(f, WIDTH_2, HEIGHT_2);
		else if (f->resolution == 1)
			set_window(f, WIDTH_1, HEIGHT_1);
		else
			set_window(f, WIDTH_0, HEIGHT_0);
		zoom_init(f);
	}
	else if (key == KEY_F)
	{
		f->cam.alpha = 0.0;
		f->cam.beta = 0.0;
		f->cam.eta = 0.0;
		if (!f->cam.flyofview)
			f->cam.flyofview = true;
		else
			f->cam.flyofview = false;
	}
}

void	handle_key2(int key, t_fdf *f)
{
	if (key == NUM_PAD_1 || key == MAIN_PAD_1)
		f->cam.alpha += 0.05;
	else if (key == NUM_PAD_9 || key == MAIN_PAD_9)
		f->cam.alpha -= 0.05;
	else if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		f->cam.beta += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		f->cam.beta -= 0.05;
	else if (key == NUM_PAD_3 || key == MAIN_PAD_3)
		f->cam.eta += 0.05;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7)
		f->cam.eta -= 0.05;
	else if (key == KEY_I)
		f->cam.zoom += f->cam.zoom_accel;
	else if (key == KEY_O)
		f->cam.zoom += -f->cam.zoom_accel;
	else
		handle_key3(key, f);
}

int	handle_key(int key, t_fdf *f)
{
	if (key == KEY_ESC)
		handle_close(f);
	else if (key == KEY_U_ARROW)
		f->cam.y_offset -= 5;
	else if (key == KEY_D_ARROW)
		f->cam.y_offset += 5;
	else if (key == KEY_L_ARROW)
		f->cam.x_offset -= 5;
	else if (key == KEY_R_ARROW)
		f->cam.x_offset += 5;
	else
		handle_key2(key, f);
	draw(f);
	return (0);
}
