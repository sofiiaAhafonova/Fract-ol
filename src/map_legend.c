#include "../include/fractol.h"

int 	put_legend(t_env *env)
{
	if (!env->show_legend)
		return (1);
	mlx_string_put(env->mlx_ptr, env->window, 20, 20, 0xFFFFFF, "LEGEND:");
	mlx_string_put(env->mlx_ptr, env->window, 20, 40, 0xFFFFFF, "Decrease/increase n: 1/2");
	mlx_string_put(env->mlx_ptr, env->window, 20, 60, 0xFFFFFF, "Zoom in/out: +/-");
	mlx_string_put(env->mlx_ptr, env->window, 20, 80, 0xFFFFFF, "Hide/show legend: h");
	mlx_string_put(env->mlx_ptr, env->window, 20, 100, 0xFFFFFF, "move: arrows");
	if (env->fractal.type == JULIA)
		mlx_string_put(env->mlx_ptr, env->window, 20, 120, 0xFFFFFF, "begin/start change: space");
	return (0);
}