#include "../include/fractol.h"

int 	put_legend(t_env *env)
{
	if (!env->show_legend)
		return (1);
	mlx_string_put(env->mlx_ptr, env->window, 20, 40, 0xFFFFFF, "CHANGE N(-/+): 1/2");
	mlx_string_put(env->mlx_ptr, env->window, 20, 60, 0xFFFFFF, "ZOOM IN/OUT: +/-");
	mlx_string_put(env->mlx_ptr, env->window, 20, 80, 0xFFFFFF, "HIDE/SHOW LEGEND: h");
	mlx_string_put(env->mlx_ptr, env->window, 20, 100, 0xFFFFFF, "MOVE: ARROWS");
	mlx_string_put(env->mlx_ptr, env->window, 20, 120, 0xFFFFFF, "CHANGE COLORS: 4");
	mlx_string_put(env->mlx_ptr, env->window, 20, 140, 0xFFFFFF, "RESET: 0");
	if (env->fractal.type == JULIA)
		mlx_string_put(env->mlx_ptr, env->window, 20, 160, 0xFFFFFF, "begin/start change: space");
	return (0);
}