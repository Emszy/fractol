#include "fractol.h"

int 	key_hook(int keycode, t_connection *obj)
{
	int x;
	x = 0;
	mlx_pixel_put(obj->mlx, obj->win, keycode, keycode, RED);
	if (keycode == 53)
		error_master5000("GOODBYE WORLD!");
	if (keycode == KEY_SPACE)
		obj->key.space = tog_key(obj->key.space);
	keymove(keycode, obj, 0.05);
	key_zoom(keycode, obj);
	display_fractol(obj);
	return(0);
}

int  	mouse_hook(int button, int x, int y, t_connection *obj)
{
	double move_speed_y;
	double move_speed_x;

	move_speed_x = map_num(x, SCREEN_WIDTH, -obj->ctrls.speed_range, obj->ctrls.speed_range);
	move_speed_y = map_num(y, SCREEN_HEIGHT, -obj->ctrls.speed_range, obj->ctrls.speed_range);
	if (button == 5)
	{	
		key_zoom(KEY_Z, obj);
		mouse_move(obj, move_speed_x, 1);
		mouse_move(obj, move_speed_y, 2);
	}
	if (button == 4)
	{	
		key_zoom(KEY_X, obj);
		mouse_move(obj, move_speed_x, 1);
		mouse_move(obj, move_speed_y, 2);
	}
	mlx_clear_window(obj->mlx, obj->win);
	display_fractol(obj);
	return (1);
}

int		tracking_hook(int x, int y, t_connection *obj)
{
		if (obj->key.space == 0 && obj->map == 2) // not zooming && is julia selected
		{
			obj->ctrls.julia_mouse_x = x;
			obj->ctrls.julia_mouse_y = y;
			mlx_clear_window(obj->mlx, obj->win);
			display_fractol(obj);
		}
	
	return (0);
}
