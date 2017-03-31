#include "../includes/fractol.h"

int display_mandelbrot(t_connection *obj, int x, int y)
{
  int n;
  t_fract   m;

  m.twoab = 0;
  n = -1;
  m.a = map_num(x, WIDTH, obj->ctrls.mag_neg1, obj->ctrls.mag_p1);
  m.b = map_num(y, HEIGHT, obj->ctrls.mag_neg2, obj->ctrls.mag_p2);
  m.ca = m.a;
  m.cb = m.b;
  while (++n <= 50)
  {
    m.bb = 2 * m.a * m.b;
    m.a = (m.a * m.a) - (m.b * m.b) + m.ca;
    m.b = m.bb + m.cb;
    if (m.a * m.a + m.b * m.b > 16)
      break;
  }
  return (n);
}

void mandelbrot(t_connection *obj)
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
      n = display_mandelbrot(obj, x, y);
      mlx_pixel_put(obj->mlx, obj->win, x , y, obj->color_wheel[n]);  
    }
  }
}