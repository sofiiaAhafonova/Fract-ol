#include "../include/fractol.h"

int 	on_mouse_click(int b, int x, int y, t_env *env)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >=SCREEN_HEIGHT)
		return (0);
	if ((b == 4 || b == 5) &&
		(x > 0 && x < SCREEN_WIDTH && y > 0 && y <SCREEN_HEIGHT))
	{
		if (b == 4)
			env->fractal.zoom *= 1.1;
		else
			env->fractal.zoom /= 1.1;
		env->offset_y = y;
		env->offset_x = x;
	}
	else if (b == 1)
	{
		env->offset_y = SCREEN_HEIGHT/2 - y;
		env->offset_x = SCREEN_WIDTH/2 - x;
	}
	else if (b == 2 && !env->right_button)
	{
		env->right_button = 1;
		env->fractal.zoom /= (1.1*x/100);

	}
	mlx_clear_window(env->mlx_ptr, env->window);
	return (choose_fractal(env));
}

int 	mouse_up(int b, int x, int y, t_env *env)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >=SCREEN_HEIGHT)
		return (0);
	if (b == 2 && env->right_button)
		env->right_button = 0;
}

int				mouse_move(int x, int y, t_env *env)
{
	if ((env->fractal.c.x && env->fractal.c.y) && (x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT))
	{
		if (env->fractal.change_on_move)
		{
			env->fractal.c.x += ((double)x - env->mouse_offset_x) / (SCREEN_WIDTH * 2);
			env->fractal.c.y += ((double)y - env->mouse_offset_y) / (SCREEN_HEIGHT * 2);
			env->mouse_offset_x = x;
			env->mouse_offset_y = y;
		}
		mlx_clear_window(env->mlx_ptr, env->window);
		return (choose_fractal(env));
	}
	return (choose_fractal(env));
}
