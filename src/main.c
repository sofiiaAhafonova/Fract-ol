/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:06:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 00:06:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int 	print_error(char *str)
{
	ft_putstr(str);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env *env;

    if (argc != 2)
        return (print_error("usage: fractol [julia/mandelbrot]\n"));
	if(!(env = init(argv[1])))
        return (print_error("Wrong fractal name\n"));
	mlx_hook(env->window, 17, 1L << 17, &close_window, env);
	mlx_hook(env->window, 2, 5, on_key_press, env);
	mlx_hook(env->window, 4, 0, on_mouse_click, env);
	mlx_hook(env->window, 6, 0, mouse_move, env);
    if (env->fractal.type == JULIA)
	{
		init_julia(env);
		julia_set(env);
	}
	else if (env->fractal.type == MANDELBROT)
	{
		init_mandelbrot(env);
		mandelbrot_set(env);
	}
	put_legend(env);
    mlx_loop(env->mlx_ptr);
	return (0);
}
