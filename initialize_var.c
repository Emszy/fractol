#include "fractol.h"

void init_window(t_connection *obj)
{
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "MZ$2");
}

void init_movement(t_connection *obj)
{
	obj->ctrls.mouse_x = 0;
	obj->ctrls.mouse_y = 0;
	obj->ctrls.mag_p1 = 2.5;
	obj->ctrls.mag_p2 = 2.5;
	obj->ctrls.mag_neg1 = -2.5;
	obj->ctrls.mag_neg2 = -2.5;
	obj->ctrls.zoom_iterations = 0;
	obj->ctrls.speed_range = 0.06;
	obj->ctrls.total_offsetx = 0;
	obj->ctrls.total_offsety = 0;
	obj->ctrls.mag = 200;
	obj->ctrls.panX = 2;
	obj->ctrls.panY = 1.5;
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
