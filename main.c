#include "fractol.h"


//#define MAP_NUM(x,a,b,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)


void error_master5000(char *message)
{
	ft_putstr(message);
	ft_putstr("\n");
	exit(-1);
}


double map_num(double num, double screen, double min_num, double max_num)
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
void display_fractol(t_connection *obj)
{
	if(obj->map == 1)
		mandelbrot(obj);
	if(obj->map == 2)
		julia(obj);
	// if(obj->map == 3)
		//menger(obj);

}

void chorus(t_connection *obj)
{
	mlx_key_hook(obj->win, key_hook, obj);
	mlx_mouse_hook(obj->win, mouse_hook, obj);
	mlx_hook(obj->win, 6, 0, tracking_hook, obj);
	
	display_fractol(obj);
	mlx_loop(obj->mlx);
}

void setmap(t_connection *obj, char *mapnum)
{
	if ((ft_strcmp(mapnum, "1") == 0))
		obj->map = 1;
	else if ((ft_strcmp(mapnum, "2") == 0))
		obj->map = 2;
	else if ((ft_strcmp(mapnum, "3") == 0))
		obj->map = 3;
	else
	{
		ft_putstr("dial \"1\" for mandelbrot\n");
		ft_putstr("dial \"2\" for julia\n");
		ft_putstr("dial \"3\" for infinisquare\n");
		error_master5000("EX: ./fractol 1");
	}
}

int main(int ac, char **av)
{	
	t_connection *obj;

	obj = malloc(sizeof(t_connection));
	initializer(obj);
	if (ac == 2)
	{
		setmap(obj, av[1]);
		chorus(obj);
	}
	 	
	return (0);
}