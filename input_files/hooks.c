#include "../includes/fractol.h"

int 	key_hook(int keycode, t_connection *obj)
{
	int x;
	x = 0;
	mlx_pixel_put(obj->mlx, obj->win, keycode, keycode, RED);
	if (keycode == 53)
		error_master5000("GOODBYE WORLD!");
	if (keycode == KEY_SPACE)
		obj->key.space = tog_key(obj->key.space);
	keymove(keycode, obj, 0.001);
	key_zoom(keycode, obj);
	display_fractol(obj);
	return(0);
}

int  	mouse_hook(int button, int x, int y, t_connection *obj)
{
	if (button == 5)
	{
		x -= obj->width / 2;
		y -= obj->height / 2;
		obj->zoom = (obj->zoom + 1) * 1.1;
		obj->x_shift += x / obj->zoom / 1.5;
		obj->y_shift += y / obj->zoom / 1.5;
	}
	else if (button == 4)
	{
		if (obj->zoom > 2)
			obj->zoom = (obj->zoom - 1) / 1.1;
		if (obj->zoom < 4)
			obj->zoom = 1;
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
