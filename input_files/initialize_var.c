#include "../includes/fractol.h"

void init_window(t_connection *obj)
{
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, WIDTH, HEIGHT, "MZ$2");
}

void init_movement(t_connection *obj)
{
	obj->max_iter = 64;
	obj->width = WIDTH;
	obj->height = HEIGHT;
	obj->mouse_x = 0;
	obj->mouse_y = 0;
	obj->zoom = 1.0;
	obj->x_shift = 0;
	obj->y_shift = 0;
	obj->ctrls.mouse_x = 0;
	obj->ctrls.mouse_y = 0;
	obj->ctrls.mag_p1 = 1;
	obj->ctrls.mag_p2 = 2.5;
	obj->ctrls.mag_neg1 = -2.5;
	obj->ctrls.mag_neg2 = -2;
	obj->ctrls.zoom_iterations = 0;
	obj->ctrls.speed_range = 1;
	obj->ctrls.angle = 0;
	obj->ctrls.angle1 = 0;
}

void initializer(t_connection *obj)
{
	init_window(obj);
	init_movement(obj);
	init_colors1(obj);
	init_colors2(obj);
}

void error_master5000(char *message)
{
	ft_putstr(message);
	ft_putstr("\n");
	exit(-1);
}

double map_num(double num, double screen, double min_num, double max_num)
{
	double perc;
	double result;
	double temp_num;

	perc = 0;
	temp_num = max_num - min_num;
	perc = num / screen;
	result = perc * temp_num;
	if (min_num < 0)
	{
		min_num = -min_num;
		result = result - min_num;
		return (result);
	}
	if (min_num > 0)
	{
		result = result + min_num;
		return (result);
	}
	return (result);
}
