/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 04/14/2017 15:43 by ebucheit             #+#    #+#             */
/*   Updated: 04/14/2017 15:43 by ebucheit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		display_mandelbrot(t_connection *obj, double x, double y)
{
	double  new;
	double  real;
	double  imaginary;
	int  n;

	x = ((4.0 * x / obj->ctrls.width - 2.0) / obj->ctrls.zoom)
		+ (obj->ctrls.pan_x / obj->ctrls.width);
	y = ((4.0 * y / obj->ctrls.height - 2.0) / obj->ctrls.zoom)
		+ (obj->ctrls.pan_y / obj->ctrls.height);
	real = 0;
	imaginary = 0;
	n = -1;
	while (++n < 50)
	{
		if (real * real + imaginary * imaginary >= 4)
			break;
		new = real * real - imaginary * imaginary + x;
		imaginary = 2 * real * imaginary + y;
		real = new;
	}
	return (n);
}

void	mandelbrot(t_connection *obj)
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
			mlx_pixel_put(obj->mlx, obj->win, x , y, \
							obj->color_wheel[n]);  
		}
	}
}
