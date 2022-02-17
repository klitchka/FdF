#include "fdf.h"

t_grad	*new_colour(t_rgb rgb)
{
	t_grad	*grad;

	grad = (t_grad *) malloc(sizeof(t_grad));
	grad->rgb.r = rgb.r;
	grad->rgb.g = rgb.g;
	grad->rgb.b = rgb.b;
	grad->next = NULL;
	return (grad);
}

void	free_palette(t_grad *grad)
{
	t_grad	*temp;

	temp = grad;
	while (grad)
	{
		temp = grad->next;
		free(grad);
		grad = temp;
	}
}

void	push_colour(t_grad **grad, t_grad *rgb)
{
	if (grad)
	{
		if (rgb)
			rgb->next = *grad;
		*grad = rgb;
	}
}

int	grad_size(t_grad *grad)
{
	int	c;

	c = 0;
	if (!grad)
		return (0);
	while (grad)
	{
		c++;
		grad = grad->next;
	}
	return (c);
}

void	palette(t_grad **grad, int c_start, int steps, int c_end)
{
	t_rgb	start;
	t_rgb	end;
	t_rgb	rgb;
	int		temp;

	temp = steps - 1;
	int_to_rgb(&start, c_start);
	int_to_rgb(&end, c_end);
	rgb.r = start.r;
	rgb.g = start.g;
	rgb.b = start.b;
	if (!*grad)
		*grad = new_colour(start);
	while (temp--)
	{
		color_node(start, steps, end, &rgb);
		push_colour(grad, new_colour(rgb));
	}
	push_colour(grad, new_colour(end));
}
