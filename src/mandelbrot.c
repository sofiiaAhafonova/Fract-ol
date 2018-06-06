#include "../include/fractol.h"

void mandelbrot_set(t_env *env)
{
	int			x;
	int 		y;
	t_complex	c;

	x = -1;
	while (++x <= SCREEN_WIDTH)
	{
		y = -1;
		c.y =  -1.2 - x * (3*SCREEN_HEIGHT/SCREEN_WIDTH)/(SCREEN_HEIGHT - 1);
		c.x = -2.0 + y*3/(SCREEN_WIDTH - 1);
		while (++y <= SCREEN_HEIGHT)
		{
//			c = map_point(env->fractal.radius, env->fractal.zoom, x, y);
			each_pixel(env, x, y, c);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image.img_ptr, 0, 0);
}