#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "key_map.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 			500
# define HEIGHT 		500
# define X_SCALE 		400
# define Y_SCALE 		400
# define WHITE 	0x00ffffff
# define GREY 	0x00878787
# define BLACK 	0x00000000
# define RED 	0x00FF0000
# define GREEN 	0x0000FF00
# define BLUE 	0x000000FF
# define YELLOW	0x00fbff23




typedef struct 	s_controls
{
	int 	mouse_x;
	int 	mouse_y;
	int 	julia_mouse_x;
	int 	julia_mouse_y;
	int 	zoom_iterations;
	double	speed_range;
	double 	mag_p1;
	double 	mag_p2;
	double 	mag_neg1;
	double 	mag_neg2;
	double 	angle;
	double	angle1;





}				t_controls;

typedef struct s_fract
{
	double a;
	double b;
	double twoab;
	double ca;
	double cb;
	double bb;
}				t_fract;

typedef struct	s_connection
{
	void			*mlx;
	void			*win;
	void			*img;
	void 			*new_img;
	int				map;
	int				color_wheel[50];
	int			max_iter;
	int			width;
	int			height;
	double		mouse_x;
	double		mouse_y;
	int			color_spin;
	int			zoom;
	double		x_shift;
	double		y_shift;
	t_keys			key;
	t_controls 		ctrls;
}				t_connection;

int 	key_hook(int keycode, t_connection *obj);
int 	mouse_hook(int button, int x, int y, t_connection *obj);
void 	error_master5000(char *message);
void 	initializer(t_connection *obj);
double 	checkIfBelongsToMandelbrotSet(double x, double y); 
void 	mandelbrot(t_connection *obj);
int 	display_mandelbrot(t_connection *obj, double re, double im);
void 	calc_color(t_connection *obj, int n, int x, int y);
double 	map_num(double num, double screen, double min_num, double max_num);
int 	display_julia(t_connection *obj, int x, int y);
void 	julia(t_connection *obj);
int		display_burning_ship(t_connection *obj, double re, double im);
void	burning_ship(t_connection *obj);
int		tracking_hook(int x, int y, t_connection *obj);
void	init_keys(t_connection *obj);
void	init_colors2(t_connection *obj);
void	init_colors1(t_connection *obj);
void	display_fractol(t_connection *obj);
int 	tog_key(int key);
void 	keymove(int keycode, t_connection *obj, double move_speed);
void 	mouse_move(t_connection *obj, double move_speed, int axis);
void 	key_zoom(int keycode, t_connection *obj);

#endif
