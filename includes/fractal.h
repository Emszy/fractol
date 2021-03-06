/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:00:32 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/18 12:00:32 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx_macos/mlx.h"
# include "key_map.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 			500
# define HEIGHT 		500

typedef struct	s_controls
{
	int			julia_mouse_x;
	int			julia_mouse_y;
	int			width;
	int			height;
	double		zoom;
	int			depth;
	double		pan_x;
	double		pan_y;
}				t_controls;

typedef struct	s_fract
{
	double		a;
	double		b;
	double		twoab;
	double		ca;
	double		cb;
	double		bb;
}				t_fract;

typedef struct	s_connection
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*new_img;
	int				map;
	int				color_wheel[75];
	t_keys			key;
	t_controls		ctrls;
}				t_connection;

int				key_hook(int keycode, t_connection *obj);
int				mouse_hook(int button, int x, int y, t_connection *obj);
void			error_master5000(char *message);
void			initializer(t_connection *obj);
void			mandelbrot(t_connection *obj);
int				display_mandelbrot(t_connection *obj, double x, double y);
double			map_num(double num, double screen, double min, double max);
int				display_julia(t_connection *obj, int x, int y);
void			julia(t_connection *obj);
int				display_burning_ship(t_connection *obj, double x, double y);
void			burning_ship(t_connection *obj);
int				tracking_hook(int x, int y, t_connection *obj);
void			init_colors3(t_connection *obj);
void			init_colors2(t_connection *obj);
void			init_colors1(t_connection *obj);
void			display_fractol(t_connection *obj);
int				tog_key(int key);

#endif
