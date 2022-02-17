#ifndef COLOR_H
# define COLOR_H

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}					t_rgb;

typedef struct s_grad
{
	t_rgb			rgb;
	struct s_grad	*next;
}					t_grad;

# define FDF_RED					0xFF0000
# define FDF_GREEN_YELLOW			0xADFF2F
# define FDF_WHITE					0xFFFFFF

//DE MAYOR A MENOR ANTIGUEDAD

//ROCAS PLUTÓNICAS VARISCAS
# define FDF_LIGHT_PINK				0xFFB6C1
# define FDF_SALMON					0xFA8072
# define FDF_ORANGE_RED				0xFF4500
# define FDF_TOMATO					0xFF6347
# define FDF_CRIMSON				0xDC143C
//MACIZO VARISCO IBÉRICO
# define FDF_DARK_SEA_GREEN			0x8FBC8F
# define FDF_DARK_OLIVE_GREEN		0x556B2F
# define FDF_TAN					0xD2B48C
//COBERTURA MESOZOICO-CENOZOICA
# define FDF_PLUM					0xDDA0DD
# define FDF_LIGHT_SKY_BLUE			0x87CEFA
# define FDF_YELLOW_GREEN			0x9ACD32
# define FDF_LIGHT_SALMON			0xFFA07A
# define FDF_GOLD					0xFFD700
# define FDF_WHEAT					0xF5DEB3
# define FDF_LIGHT_GRAY				0xD3D3D3

void	int_to_rgb(t_rgb *ret, int color);
t_rgb	get_color(t_rgb start, t_rgb end, double percent);
int		get_color_index(int z, int size);
void	color_node(t_rgb start, int steps, t_rgb end, t_rgb *rgb);
void	free_palette(t_grad *grad);
int		grad_size(t_grad *grad);
void	palette(t_grad **grad, int c_start, int steps, int c_end);
t_grad	*palettes(void);
void	**palettes_to_arr(t_grad *grad);
#endif