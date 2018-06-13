#include "../include/fractol.h"

int 	on_mouse_click(int b, int x, int y, t_env *env)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >=SCREEN_HEIGHT
		/* || e->mouse_stop == 1*/)
		return (0);
	if ((b == 4 || b == 5) &&
		(x > 280 && x < SCREEN_WIDTH && y > 0 && y <SCREEN_HEIGHT))
	{
		if (b == 4)
			env->fractal.zoom *= 1.1;
		else
			env->fractal.zoom /= 1.1;
	}
	else
	{
		env->offset_y = y;
		env->offset_x = x;
	}

	mlx_clear_window(env->mlx_ptr, env->window);
	return (choose_fractal(env));
}
