#include "fdf.h"

t_mouse	mouse_init(void)
{
	t_mouse	mouse;

	mouse.is_pressed = false;
	mouse.x = 0;
	mouse.y = 0;
	mouse.previous_x = 0;
	mouse.previous_y = 0;
	mouse.left_b = false;
	mouse.right_b = false;
	return (mouse);
}

int	mouse_press(int button, int x, int y, t_fdf *f)
{
	f->mouse.x = x;
	f->mouse.y = y;
	if (button == MOUSE_LEFT_B)
		f->mouse.left_b = true;
	else if (button == MOUSE_RIGHT_B)
		f->mouse.right_b = true;
	if (!f->mouse.right_b && button == MOUSE_SCROLL_UP)
		f->cam.z_zoom += f->cam.z_accel;
	if (!f->mouse.right_b && button == MOUSE_SCROLL_DOWN)
		f->cam.z_zoom -= f->cam.z_accel;
	if (f->mouse.right_b && button == MOUSE_SCROLL_UP)
		f->cam.zoom += f->cam.zoom_accel;
	if (f->mouse.right_b && button == MOUSE_SCROLL_DOWN)
		f->cam.zoom -= f->cam.zoom_accel;
	draw(f);
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *f)
{
	f->mouse.x = x;
	f->mouse.y = y;
	if (button == MOUSE_LEFT_B)
		f->mouse.left_b = false;
	if (button == MOUSE_RIGHT_B)
		f->mouse.right_b = false;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *f)
{
	if (f->mouse.left_b == false && f->mouse.right_b == false)
		return (0);
	f->mouse.previous_x = f->mouse.x;
	f->mouse.previous_y = f->mouse.y;
	f->mouse.x = x;
	f->mouse.y = y;
	if (f->mouse.left_b)
	{
		f->cam.beta += (x - f->mouse.previous_x) * 0.002;
		f->cam.alpha += (y - f->mouse.previous_y) * 0.002;
	}
	if (f->mouse.right_b)
		f->cam.eta -= (x - f->mouse.previous_x) * 0.002;
	draw(f);
	return (0);
}
