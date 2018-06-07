#include "../include/fractol.h"


void	each_iter(t_env *env, int x, int y, t_complex c)
{
	int			i;
	t_complex	z1;

	i = 0;
	while (c.x *c.x < 4 && ++i <= env->fractal.n)
	{
		z1 = add(sqr(c),env->fractal.c);
		if (mod(z1) > env->fractal.radius * env->fractal.radius)
		{
			env->image.data[y * SCREEN_WIDTH + x] =  env->fractal.color_func(i);
			break;
		}
		c = z1;
	}
	if (i > env->fractal.n)
		env->image.data[y * SCREEN_WIDTH + x] = 0;
}


void mandelbrot_set(t_env *env)
{
	int			x;
	int 		y;
	t_complex	c;

	y = -1;
	while (++y <= SCREEN_HEIGHT)
	{
		x = -1;
		while (++x <= SCREEN_WIDTH)
		{
			c = map_point(env->fractal.radius, env->fractal.zoom, x, y);
 			each_iter(env, x, y, c);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image.img_ptr, 0, 0);
}