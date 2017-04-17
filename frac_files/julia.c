/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 04/14/2017 15:43 by ebucheit             #+#    #+#             */
/*   Updated: 04/14/2017 15:43 by ebucheit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		display_julia(t_connection *obj, int x, int y)
{
	t_fract   	m;
	int 		n;

	m.twoab = 0;
	n = -1;
	m.a = ((4.0 * x / obj->ctrls.width - 2.0) / obj->ctrls.zoom) + \
			(obj->ctrls.pan_x / obj->ctrls.width);
	m.b = ((4.0 * y / obj->ctrls.height - 2.0) / obj->ctrls.zoom) + \
			(obj->ctrls.pan_y / obj->ctrls.height);
	m.ca = map_num(obj->ctrls.julia_mouse_x, WIDTH, 1, -1);
	m.cb = map_num(obj->ctrls.julia_mouse_y, HEIGHT, 1, -1);
	while (++n < 50)
	{
		if (fabs(m.a + m.b) > 8)
			break;
		m.twoab = 2 * m.a * m.b;
		m.a = (m.a * m.a) - (m.b * m.b) + m.ca;
		m.b = m.twoab + m.cb;
	}
	return (n);
}


void	julia(t_connection *obj)
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
