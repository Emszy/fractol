#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 200
#define X_SCALE 100
#define Y_SCALE 100

#define WHITE 	0x00ffffff
#define GREY 	0x00878787
#define BLACK 	0x00000000
#define RED 	0x00FF0000
#define GREEN 	0x0000FF00
#define BLUE 	0x000000FF
#define YELLOW	0x00fbff23

typedef struct 	s_pts
{
	int x;
	int y;
	int color;

}				t_pts;

typedef struct 	s_controls
{
	int mouse_x;
	int mouse_y;
	float zoom_p;
	float zoom_n;
	float mag;
	float panX;
	float panY;
	int x_offset;
	int y_offset;
}				t_controls;



typedef struct	s_connection
{
	void			*mlx;
	void			*win;
	void			*img;

	t_controls ctrls;
	t_pts		*pts;

}				t_connection;
int julia(t_connection *obj);
int mandelbrot(t_connection *obj);
float checkIfBelongsToMandelbrotSet(float x, float y);
int mandelbrot2(t_connection *obj);
void error_master5000(char *message);
int hook_and_loop(t_connection *obj);
int key_hook(int keycode, t_connection *obj);
int mouse_hook(int button, int x, int y, t_connection *obj);
int loop_hook(t_connection *obj);

#endif
