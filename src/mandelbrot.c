#include "../include/fractol.h"
#include <math.h>

int				calc_color_mandelbrot(int i)
{
	return ((i << 10) + i * 8);
}
t_complex calc_z_mandelbrot(t_env *env, t_complex c, t_complex z0)
{
	if (!env)
		return (c);
	t_complex buf;

	buf.x = z0.x * z0.x - z0.y * z0.y;
	buf.y = 2 * z0.x * z0.y;
	return add_complex(buf, c);
}
void	each_iter(t_env *env, int x, int y, t_complex c)
{
	int			i;
	t_complex	z0;
	t_complex	buf;

	i = 0;
	z0.x = c.x;
	z0.y = c.y;
	while (z0.x*z0.x + z0.y * z0.y <= 4 && ++i <= env->fractal.n)
	{
		buf.x = z0.x * z0.x - z0.y * z0.y;
		buf.y = 2 * z0.x * z0.y;
		z0.x = buf.x + c.x;
		z0.y = buf.y + c.y;
//		z0 =calc_z_mandelbrot(env, c, z0);// add_complex(sqr_complex(z0), c);
	}
	if (i > env->fractal.n)
		env->image.data[y * SCREEN_WIDTH + x] = 0;
	else
		env->image.data[y * SCREEN_WIDTH + x] = i + env->fractal.color_func(i) ;
}



void mandelbrot_set(t_env *env)
{
	int			x;
	int 		y;
	t_complex	c;
	int 		l;

	x = -1;
	l = SCREEN_WIDTH < SCREEN_HEIGHT ? SCREEN_WIDTH : SCREEN_HEIGHT;
	while (++x < SCREEN_WIDTH)
	{
		y = -1;
		c.y = (2 * y - SCREEN_HEIGHT) / (SCREEN_HEIGHT * env->fractal.zoom) + env->offset_y;
		while (++y < SCREEN_HEIGHT)
		{
			c.x = 4 * (x - SCREEN_WIDTH / 2.0) / (l * env->fractal.zoom);
			c.y = 4 * (y - SCREEN_HEIGHT / 2.0) / (l * env->fractal.zoom);
			each_iter(env, x, y, c);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->image.img_ptr, 0, 0);
}