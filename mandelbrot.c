#include "fractol.h"

int display_mandelbrot(t_connection *obj, int x, int y)
{
  double a;
  double b;
  double n;
  double twoab;
  double ca;
  double cb;
  double bb;

  twoab = 0;
  n = 0;
  a = map_num(x, SCREEN_WIDTH, obj->ctrls.mag_neg1, obj->ctrls.mag_p1);
  b = map_num(y, SCREEN_HEIGHT, obj->ctrls.mag_neg2, obj->ctrls.mag_p2);

  ca = a;
  cb = b;
      while (n <= 50) {
        bb = 2 * a * b;
        a = (a * a) - (b * b) + ca;
        b = bb + cb;
        if (a * a + b * b > 16) {
          break;
        }
        n++;
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
  while(++x <= SCREEN_WIDTH)
  {
    y = -1;
    while(++y <= SCREEN_HEIGHT)
    {   
      n = display_mandelbrot(obj, x, y);
      mlx_pixel_put(obj->mlx, obj->win, x , y, obj->color_wheel[n]);  
    }
  }
}