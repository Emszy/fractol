/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 04/14/2017 15:43 by ebucheit             #+#    #+#             */
/*   Updated: 04/14/2017 15:43 by ebucheit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_window(t_connection *obj)
{
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, WIDTH, HEIGHT, "MZ$2");
}

void	init_movement(t_connection *obj)
{
	obj->ctrls.width = 		WIDTH;
	obj->ctrls.height = 	HEIGHT;
	obj->ctrls.zoom = 		0.9;
	obj->ctrls.depth = 		0;
	obj->ctrls.pan_x = 		0;
	obj->ctrls.pan_y = 		0;
	obj->key.space = 		0;
}

void 	initializer(t_connection *obj)
{
	init_window(obj);
	init_movement(obj);
	init_colors1(obj);
	init_colors2(obj);
}

void	error_master5000(char *message)
{
	ft_putstr(message);
	ft_putstr("\n");
	exit(-1);
}

double	map_num(double num, double screen, double min_num, double max_num)
{
	double perc;
	double result;
	double temp_num;

	perc = 0;
	temp_num = max_num - min_num;
	perc = num / screen;
	result = perc * temp_num;
	if (min_num < 0)
	{
		min_num = -min_num;
		result = result - min_num;
		return (result);
	}
	if (min_num > 0)
	{
		result = result + min_num;
		return (result);
	}
	return (result);
}
