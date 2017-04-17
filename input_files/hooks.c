/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 04/14/2017 15:43 by ebucheit             #+#    #+#             */
/*   Updated: 04/14/2017 15:43 by ebucheit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		tog_key(int key)
{
	if (key == 0)
		key = 1;
	else
		key = 0;
	return (key);
}

int 	key_hook(int keycode, t_connection *obj)
{
	int x;
	x = 0;
	if (keycode == 53)
		error_master5000("GOODBYE WORLD!");
	if (keycode == KEY_SPACE)
		obj->key.space = tog_key(obj->key.space);
	display_fractol(obj);
	return(0);
}

int  	mouse_hook(int button, int x, int y, t_connection *obj)
{
	if (button == 5)
	{
		x = x - obj->ctrls.width / 2;
		y = y - obj->ctrls.height / 2;
		obj->ctrls.zoom = (obj->ctrls.zoom + 1) * 1.1;
		if (obj->ctrls.depth < 5)
		{
			obj->ctrls.pan_x += x / obj->ctrls.zoom * 5;
			obj->ctrls.pan_y += y / obj->ctrls.zoom * 5;
		}
		else
		{
			obj->ctrls.pan_x += x / obj->ctrls.zoom / 1.1;
			obj->ctrls.pan_y += y / obj->ctrls.zoom / 1.1;
		}
	}
	else if (button == 4)
	{
		obj->ctrls.depth--;
		if (obj->ctrls.zoom > 2)
			obj->ctrls.zoom = (obj->ctrls.zoom - 1) / 1.1;
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
