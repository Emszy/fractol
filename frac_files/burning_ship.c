/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 04/14/2017 15:43 by ebucheit             #+#    #+#             */
/*   Updated: 04/14/2017 15:43 by ebucheit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int display_burning_ship(t_connection *obj, double re, double im)
{
  double  x_new;
  double  x;
  double  y;
  int   i;

  re = ((4.0 * re / obj->width - 2.0) / obj->zoom)
    + (obj->x_shift / obj->width);
  im = ((4.0 * im / obj->height - 2.0) / obj->zoom)
    + (obj->y_shift / obj->height);
  x = 0;
  y = 0;
  i = 0;
  while (x * x + y * y <= 4 && i < obj->max_iter)
  {
    x_new = fabs(x * x - y * y + re);
    y = fabs(2 * x * y + im);
    x = x_new;
    i++;
  }
  return (i);
}

void burning_ship(t_connection *obj)
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
      n = display_burning_ship(obj, x, y);
      mlx_pixel_put(obj->mlx, obj->win, x , y, obj->color_wheel[n]);  
    }
  }
}
