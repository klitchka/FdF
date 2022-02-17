#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"

# define BUFFER_SIZE 127
# define MAX_FD 1024

# include "libft.h"
# include "keys.h"
# include "color.h"

# define HEIGHT_2		1080
# define WIDTH_2		1920
# define HEIGHT_1		768
# define WIDTH_1		1024
# define HEIGHT_0		600
# define WIDTH_0		800
# define D_MIN			64
# define D_MAX			96

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_MAP_READING	"Reading error"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CONV_TO_ARR	"Conversion to array"
# define ERR_CAMERA_INIT	"Camera initialization error"
# define ERR_IMG			"Icons error"

typedef struct s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct s_img
{
	void			*ptr;
	char			*addr;
}				t_img;

typedef struct s_pt
{
	int		x;
	int		y;
	int		z;
	t_rgb	rgb;
}					t_pt;

typedef struct s_camera
{
	double			zoom;
	double			zoom_accel;
	double			z_zoom;
	double			z_accel;
	double			alpha;
	double			beta;
	double			eta;
	int				x_offset;
	int				y_offset;
	bool			flyofview;
}					t_camera;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
	bool	left_b;
	bool	right_b;
}					t_mouse;

typedef struct s_map
{
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	int		*coords_arr;
	int		*colors_arr;
	bool	map_color;
}					t_map;

typedef struct s_var
{
	double	dx;
	double	dy;
	double	gradient;
	double	xend;
	double	yend;
	double	xgap;
	double	ygap;
	double	intery;
	double	interx;
	int		xpxl1;
	int		ypxl1;
	int		xpxl2;
	int		ypxl2;
	bool	swap;
}					t_var;

typedef struct s_fdf
{
	void		**grad;
	t_grad		*palettes;
	t_map		*map;
	t_map		*floor;
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_camera	cam;
	t_mouse		mouse;
	int			grad_size;
	int			bits_per_pix;
	int			size_line;
	int			resolution;
}					t_fdf;

typedef struct s_coord_val
{
	int					z;
	int					rgb;
	struct s_coord_val	*next;
}						t_coord_val;

int			ipart(double x);
double		fpart(double x);
double		rfpart(double x);
int			fround(double x);
double		curr_percent(int start, int curr, int end);
void		if_e(bool is_error, int val, char *msg);
void		free_arr(char **arr);
int			hextoi(const char *str);
int			handle_close(t_fdf *f);
int			handle_key(int key, t_fdf *f);
t_mouse		mouse_init(void);
int			mouse_press(int button, int x, int y, t_fdf *f);
int			mouse_release(int button, int x, int y, t_fdf *f);
int			mouse_move(int x, int y, t_fdf *f);
void		plot_line(t_fdf *f, t_pt p0, t_pt p1);
int			draw(t_fdf *f);
int			read_map(const int fd, t_coord_val **coords_stack, t_fdf *f);
void		get_map(t_coord_val **coords_stack, t_fdf *f);
t_pt		project(t_pt p, t_fdf *f);
t_pt		apply_color(int x, int y, t_fdf *f);
int			apply_brightness(t_rgb rgb, double brightness);
void		zoom_init(t_fdf *f);
void		set_window(t_fdf *f, int width, int heigth);
void		resolution(t_fdf *f);
void		plot_pixel(t_fdf *f, int x, int y, int rgb);
void		plot_line_wiki(t_fdf *f, t_pt p0, t_pt p1);
#endif
