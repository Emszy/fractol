#include "fractol.h"
int tog_key(int key)
{
	if (key == 0)
		key = 1;
	else
		key = 0;
	return (key);
}


void keymove(int keycode, t_connection *obj, double move_speed)
{
	if (keycode == KEY_RIGHT)
	{
		obj->ctrls.mag_p1 = obj->ctrls.mag_p1 - move_speed;
		obj->ctrls.mag_neg1 = obj->ctrls.mag_neg1 - move_speed;
	}
	if (keycode == KEY_LEFT)
	{
		obj->ctrls.mag_p1 = obj->ctrls.mag_p1 + move_speed;
		obj->ctrls.mag_neg1 = obj->ctrls.mag_neg1 + move_speed;
	}
	if (keycode == KEY_DOWN)
	{
		obj->ctrls.mag_p2 = obj->ctrls.mag_p2 - move_speed;
		obj->ctrls.mag_neg2 = obj->ctrls.mag_neg2 - move_speed;
	}
	if (keycode == KEY_UP)
	{
		obj->ctrls.mag_p2 = obj->ctrls.mag_p2 + move_speed;
		obj->ctrls.mag_neg2 = obj->ctrls.mag_neg2 + move_speed;
	}
}


void mouse_move(t_connection *obj, double move_speed, int axis)
{

	if (axis == 1)
	{
		obj->ctrls.mag_p1 = obj->ctrls.mag_p1 + move_speed;
		obj->ctrls.mag_neg1 = obj->ctrls.mag_neg1 + move_speed;
	}
	if (axis == 2)
	{
		obj->ctrls.mag_p2 = obj->ctrls.mag_p2 + move_speed;
		obj->ctrls.mag_neg2 = obj->ctrls.mag_neg2 + move_speed;
	}
}

void key_zoom(int keycode, t_connection *obj)
{

	double zoom_lvl;

	zoom_lvl = 0.99;
	if (keycode == KEY_Z)
	{
		obj->ctrls.mag_p1 = obj->ctrls.mag_p1 * zoom_lvl;
		obj->ctrls.mag_neg1 = obj->ctrls.mag_neg1 * zoom_lvl;
		obj->ctrls.mag_p2 = obj->ctrls.mag_p2 * zoom_lvl;
		obj->ctrls.mag_neg2 = obj->ctrls.mag_neg2 * zoom_lvl;
		obj->ctrls.zoom_iterations++;
	}
	if (keycode == KEY_X)
	{
		obj->ctrls.mag_p1 = obj->ctrls.mag_p1 / zoom_lvl;
		obj->ctrls.mag_neg1 = obj->ctrls.mag_neg1 / zoom_lvl;
		obj->ctrls.mag_p2 = obj->ctrls.mag_p2 / zoom_lvl;
		obj->ctrls.mag_neg2 = obj->ctrls.mag_neg2 / zoom_lvl;
		obj->ctrls.zoom_iterations--;
	}
	

	printf("%d\n", obj->ctrls.zoom_iterations);
}
