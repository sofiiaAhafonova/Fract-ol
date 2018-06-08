#include "../include/fractol.h"
#include <math.h>

int				calc_color_mandelbrot(int i)
{
	return ((i << 10) + i * 8);
}

void	each_iter(t_env *env, int x, int y, t_complex c)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	i = 0;
	z0.x = 0;
	z0.y = 0;
	while (z0.x*z0.x + z0.y * z0.y <= 4 && ++i <= env->fractal.n)
	{
//		z1 = add(sqr(c),env->fractal.c);
		z1.x = z0.x * z0.x;
		z1.y = z0.y * z0.y;
		z0.y = 2*z0.x*z0.y + c.y;
		z0.x = z1.x - z1.y + c.x;
	}
	if (i > env->fractal.n)
		env->image.data[y * SCREEN_WIDTH + x] = 0;
	else
		env->image.data[y * SCREEN_WIDTH + x] = i + 1 - (int)(log(log(mod(z0)))/log(5));//env->fractal.color_func(i) ;
}


void mandelbrot_set(t_env *env)
{
	int			x;
	int 		y;
	t_complex	c;
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+((MaxRe-MinRe)*SCREEN_HEIGHT)/SCREEN_WIDTH;
	double Re_factor = (MaxRe-MinRe)/(SCREEN_WIDTH-1);
	double Im_factor = (MaxIm-MinIm)/(SCREEN_HEIGHT-1);

	y = -1;
	while (++y <= SCREEN_HEIGHT)
	{
		x = -1;
		c.y =(y - SCREEN_HEIGHT/2.0)*4.0/SCREEN_WIDTH;
		while (++x <= SCREEN_WIDTH)
		{
		//	c = map_point(env->fractal.radius, env->fractal.zoom, x, y);
 			c.x = (x - SCREEN_WIDTH/2.0)*4.0/SCREEN_WIDTH;
 			each_iter(env, x, y, c);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image.img_ptr, 0, 0);
}