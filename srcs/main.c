/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 21:22:45 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/15 21:30:29 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	you_effed_up(void)
{
	ft_putstr("dial \"1\" for mandelbrot\n");
	ft_putstr("dial \"2\" for julia\n");
	ft_putstr("dial \"3\" for burning ship\n");
	error_master5000("EX: ./fractol 1");
}

void	display_fractol(t_connection *obj)
{
	if (obj->map == 1)
		mandelbrot(obj);
	if (obj->map == 2)
		julia(obj);
	if (obj->map == 3)
		burning_ship(obj);
}

void	chorus(t_connection *obj)
{
	mlx_key_hook(obj->win, key_hook, obj);
	mlx_mouse_hook(obj->win, mouse_hook, obj);
	mlx_hook(obj->win, 6, 0, tracking_hook, obj);
	display_fractol(obj);
	mlx_loop(obj->mlx);
}

void	setmap(t_connection *obj, char *mapnum)
{
	if ((ft_strcmp(mapnum, "1") == 0))
		obj->map = 1;
	else if ((ft_strcmp(mapnum, "2") == 0))
		obj->map = 2;
	else if ((ft_strcmp(mapnum, "3") == 0))
		obj->map = 3;
	else
		you_effed_up();
}

int		main(int ac, char **av)
{
	t_connection *obj;

	obj = malloc(sizeof(t_connection));
	initializer(obj);
	if (ac == 2)
	{
		setmap(obj, av[1]);
		chorus(obj);
	}
	else
		you_effed_up();
	return (0);
}
