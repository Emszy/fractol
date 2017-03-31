#include "../includes/fractol.h"

int display_julia(t_connection *obj, int x, int y)
{
	t_fract   	m;
	int 		n;

	m.twoab = 0;
	n = -1;
	m.a = map_num(x, WIDTH, obj->ctrls.mag_neg1, obj->ctrls.mag_p1);
	m.b = map_num(y, HEIGHT, obj->ctrls.mag_neg2, obj->ctrls.mag_p2);
	m.ca = map_num(obj->ctrls.julia_mouse_x, WIDTH, 1, -1);
	m.cb = map_num(obj->ctrls.julia_mouse_y, HEIGHT, 1, -1);
	while (++n < 50)
	{
		if (fabs(m.a + m.b) > 8)
			break;
		m.twoab = 2 * m.a * m.b;
		m.a = (m.a * m.a) - (m.b * m.b) - m.ca;
		m.b = m.twoab - m.cb;
	}
	return (n);
}

void julia(t_connection *obj)
{
	int x;
	int y;
	int n;

	n = 0;	
	x = -1;
	while(++x <= WIDTH)
	{
		y = -1;
		while(++y <= HEIGHT)
		{   
			n = display_julia(obj, x, y);
			mlx_pixel_put(obj->mlx, obj->win, x , y, obj->color_wheel[n]);  
		}
	}
}