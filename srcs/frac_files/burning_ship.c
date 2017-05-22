/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 21:22:45 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/15 21:30:29 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"

int		display_burning_ship(t_connection *obj, double x, double y)
{
	double		real;
	double		imaginary;
	double		new;
	int			n;

	real = 0;
	imaginary = 0;
	n = -1;
	x = ((4.0 * x / obj->ctrls.width - 2.0) / obj->ctrls.zoom)
		+ (obj->ctrls.pan_x / obj->ctrls.width);
	y = ((4.0 * y / obj->ctrls.height - 2.0) / obj->ctrls.zoom)
		+ (obj->ctrls.pan_y / obj->ctrls.height);
	while (++n < 49)
	{
		if (real * real + imaginary * imaginary >= 4)
			break ;
		new = fabs(real * real - imaginary * imaginary + x);
		imaginary = fabs(2 * real * imaginary + y);
		real = new;
	}
	return (n);
}

void	burning_ship(t_connection *obj)
{
	int		x;
	int		y;
	int		n;

	n = 0;
	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			n = display_burning_ship(obj, x, y);
			mlx_pixel_put(obj->mlx, obj->win, x, y, \
						obj->color_wheel[n]);
		}
	}
}
