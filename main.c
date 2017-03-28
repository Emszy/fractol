#include "fractol.h"


void error_master5000(char *message)
{
	ft_putstr(message);
	ft_putstr("\n");
	exit(-1);
}

float map_num(float num, float screen, float min_num, float max_num)
{
	float perc;
	float result;
	float temp_num;

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

void calc_color(t_connection *obj, int n, int x, int y)
{
	if (n >= 0 && n <= 10)
		mlx_pixel_put(obj->mlx, obj->win, x, y, BLACK);
	else if (n > 10 && n <= 20)
		mlx_pixel_put(obj->mlx, obj->win, x, y, BLUE);
	else if (n > 20 && n <= 30)
		mlx_pixel_put(obj->mlx, obj->win, x, y, RED);
	else if (n > 30 && n <= 40)
		mlx_pixel_put(obj->mlx, obj->win, x, y, WHITE);
	else if (n > 40 && n < 50)
		mlx_pixel_put(obj->mlx, obj->win, x, y, YELLOW);
	else
		mlx_pixel_put(obj->mlx, obj->win, x, y, GREY);
}

float checkIfBelongsToMandelbrotSet(float x, float y) 
{
    float realComponentOfResult = x;
    float imaginaryComponentOfResult = y;
    float maxIterations = 50;
    for(float i = 0; i < maxIterations; i++) 
    {
         float tempRealComponent = realComponentOfResult * realComponentOfResult
                                 - imaginaryComponentOfResult * imaginaryComponentOfResult
                                 + x;
         float tempImaginaryComponent = 2 * realComponentOfResult * imaginaryComponentOfResult
                                 + y;
         realComponentOfResult = tempRealComponent;
         imaginaryComponentOfResult = tempImaginaryComponent;
         // Return a number as a percentage
         if(realComponentOfResult * imaginaryComponentOfResult > 4) 
            return (i/maxIterations * 50);
    }
    return 0;   // Return zero if in set        
}          
int mandelbrot2(t_connection *obj)
{
	
for(float x = 0; x < SCREEN_WIDTH; x++) 
{
   for(float y = 0; y < SCREEN_HEIGHT; y++) 
   {
       float belongsToSet = 
            checkIfBelongsToMandelbrotSet(x / obj->ctrls.mag - obj->ctrls.panX,
                                          y / obj->ctrls.mag - obj->ctrls.panY);
       
       if(belongsToSet == 0)
           mlx_pixel_put(obj->mlx, obj->win, x , y, WHITE);      
   } 
}
return (1);
}

int display_julia(t_connection *obj, int x, int y)
{

	float a;
	float b;
	float n;
	float twoab;

	twoab = 0;
	n = 0;

	a = map_num(x, SCREEN_WIDTH, obj->ctrls.zoom_n, obj->ctrls.zoom_p);
	b = map_num(y, SCREEN_HEIGHT, obj->ctrls.zoom_n, obj->ctrls.zoom_p);

	printf("%f\n", a);
	n = 0;
	while(n < 50)
	{
		twoab = 2 * a * b;
		a = (a * a) - (b * b) - 0.70176;
		b = twoab - 0.3842;
		if (fabs(a + b) > 2)
			break;
		n++;
	}
	return(n);
}

int julia(t_connection *obj)
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
			n = display_julia(obj, x, y);
			calc_color(obj, n, x, y);
		}
	}
	return (0);
}

int change_screen_color(t_connection *obj, int color)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while(++i <= SCREEN_HEIGHT)
	{
		j = 0;
		while(++j <= SCREEN_WIDTH)
			mlx_pixel_put(obj->mlx, obj->win, i, j, color);
	}
	return (0);
}

int main(int ac, char **av)
{	
	t_connection *obj;

	obj = malloc(sizeof(t_connection));
	obj->pts = malloc(sizeof(t_pts) * (SCREEN_WIDTH * SCREEN_HEIGHT));
	obj->ctrls.mouse_x = 0;
	obj->ctrls.mouse_y = 0;
	obj->ctrls.zoom_p = 2;
	obj->ctrls.zoom_n = -2;
	obj->ctrls.x_offset = 0;
	obj->ctrls.y_offset = 0;
	obj->ctrls.mag = 100;
	obj->ctrls.panX = 2;
	obj->ctrls.panY = 1.5;
	if (ac > 1 && av[1])
	{
		printf("%s\n", "YUP");
	}
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "MZ$2");
	//change_screen_color(obj, GREY);
	mandelbrot2(obj);
	//julia(obj);
	hook_and_loop(obj);

	return (0);
}