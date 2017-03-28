#include "fractol.h"

int center_fractol(t_connection *obj, int x, int y, int flag)
{
	int half_width;
	int half_height;

	int x_diff;
	int y_diff;
	mlx_pixel_put(obj->mlx, obj->win, x, y, RED);

	x_diff = 0;
	y_diff = 0;

	half_width = SCREEN_WIDTH / 2;
	half_height = SCREEN_HEIGHT / 2;
	flag = 1;
	
		obj->ctrls.x_offset = x - half_width;
		obj->ctrls.y_offset = y - half_height;

	// if(obj->ctrls.x_offset >= 0 && obj->ctrls.y_offset >= 0)
	// {
	// 	obj->ctrls.zoom_p += 2;
	// 	obj->ctrls.zoom_p -= 0.5;
	// 	printf("WEINHERERERE\n");
	// }
	
	return(0);


}

int key_hook(int keycode, t_connection *obj)
{
	mlx_pixel_put(obj->mlx, obj->win, keycode, keycode, RED);
	if (keycode == 53)
		error_master5000("GOODBYE WORLD!");
	if (keycode == 6)
	{
		obj->ctrls.mag =  obj->ctrls.mag + 100;
		// obj->ctrls.panX -= 0.1;
		// obj->ctrls.panY -= 0.1;
		//obj->ctrls.zoom_n  /= 1.1;
		mlx_clear_window(obj->mlx, obj->win);
		mandelbrot2(obj);
	}
	if (keycode == 7)
	{
		obj->ctrls.zoom_p *= 0.9;
		obj->ctrls.zoom_n  *= 0.9;
		mlx_clear_window(obj->mlx, obj->win);

	}
	if (keycode == 123)
	{
		obj->ctrls.panX += 0.1;
		mlx_clear_window(obj->mlx, obj->win);
		mandelbrot2(obj);
	}
	if (keycode == 124)
	{
		obj->ctrls.panX -= 0.1;
		mlx_clear_window(obj->mlx, obj->win);
		mandelbrot2(obj);
	}
	if (keycode == 125)
	{
		obj->ctrls.panY -= 0.1;
		mlx_clear_window(obj->mlx, obj->win);
		mandelbrot2(obj);
	}
	if (keycode == 126)
	{
		obj->ctrls.panY += 0.1;
		mlx_clear_window(obj->mlx, obj->win);
		mandelbrot2(obj);
	}
		

	printf("%d\n", keycode);
	return(0);
}

int  mouse_hook(int button, int x, int y, t_connection *obj)
{
	
	mlx_pixel_put(obj->mlx, obj->win, x, y, RED);
	obj->ctrls.mouse_x = x;
	obj->ctrls.mouse_y = y;
	if(button == 5)
	{	
		center_fractol(obj,x,y,1);
		obj->ctrls.zoom_p *= 0.9;
		obj->ctrls.zoom_n  *= 0.9;
		mlx_clear_window(obj->mlx, obj->win);
		
		julia(obj);
	}
	if (button == 4)
	{
		obj->ctrls.zoom_p /= 0.9;
		obj->ctrls.zoom_n  /= 0.9;
		mlx_clear_window(obj->mlx, obj->win);
		center_fractol(obj,x,y, 2);
		julia(obj);
	}	
	return (1);
}

int loop_hook(t_connection *obj)
{
	
	printf("%d\n", obj->ctrls.mouse_x);
	printf("%d\n", obj->ctrls.mouse_y);
	return (0);
}

int hook_and_loop(t_connection *obj)
{
	mlx_key_hook(obj->win, key_hook, obj);
	mlx_mouse_hook(obj->win, mouse_hook, obj);
	//mlx_loop_hook(obj->mlx, loop_hook, obj);
	mlx_loop(obj->mlx);
	return (1);
}