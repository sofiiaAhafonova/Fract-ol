#include "../include/fractol.h"

int 	put_legend(t_env *env)
{
	char	*buf;

	if (!env->show_legend)
		return (1);
	mlx_string_put(env->mlx_ptr, env->window, 20, 20, 0xFFFFFF, "LEGEND:");
	mlx_string_put(env->mlx_ptr, env->window, 20, 40, 0xFFFFFF, "X:");
	buf = ft_itoa(env->mouse_offset_x);
	mlx_string_put(env->mlx_ptr, env->window, 40, 40, 0xFFFFFF, buf);
	free(buf);
	mlx_string_put(env->mlx_ptr, env->window, 20, 60, 0xFFFFFF, "Y:");
	buf = ft_itoa(env->mouse_offset_y);
	mlx_string_put(env->mlx_ptr, env->window, 40, 60, 0xFFFFFF, buf);
	free(buf);
	return (0);
}