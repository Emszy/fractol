#include "fractol.h"

int display_julia(t_connection *obj, int x, int y)
{
	double a;
	double b;
	double n;
	double twoab;

	twoab = 0;
	n = 0;
	a = map_num(x, SCREEN_WIDTH, obj->ctrls.mag_neg1, obj->ctrls.mag_p1);
	b = map_num(y, SCREEN_HEIGHT, obj->ctrls.mag_neg2, obj->ctrls.mag_p2);
	n = 0;
	while(n < 50)
	{
		if (fabs(a + b) > 8)
			break;
		twoab = 2 * a * b;
		a = (a * a) - (b * b) - map_num(obj->ctrls.julia_mouse_x, SCREEN_WIDTH, 1, -1);
		b = twoab - map_num(obj->ctrls.julia_mouse_y, SCREEN_HEIGHT, 1, -1);;
				n++;
	}
	return(n);
}

void julia(t_connection *obj)
{
	int x;
	int y;
	int n;

	n = 0;	
	x = -1;
	while(++x <= SCREEN_WIDTH)
	{
		y = -1;
		while(++y <= SCREEN_HEIGHT)
		{   
			n = display_julia(obj, x, y);
			mlx_pixel_put(obj->mlx, obj->win, x , y, obj->color_wheel[n]);  
		}
	}
}