/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:29:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 00:29:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		close_window(t_env *env)
{
	remove_env(env);
//	system("leaks fractol");
	exit(EXIT_SUCCESS);
}

int		choose_fractal(t_env *env)
{
	if (env->fractal->type == JULIA)
		julia_set(env);
	else if (env->fractal->type == MANDELBROT)
		mandelbrot_set(env);
	return (0);
}

int		on_key_press(int key, t_env *env)
{
	if (key == ESC)
		return (close_window(env));
	else if (key == 49 || key == 50)
		env->fractal->radius = key == 49 ? env->fractal->radius - 0.1 : env->fractal->radius + 0.1;
	else if (key == 18 && env->fractal->n > 1)
		env->fractal->n--;
	else if (key == 19)
		env->fractal->n++;
	else if (key == 20)
		env->fractal->radius++;
	else if (key == 21)
		env->fractal->radius--;
	else if (key == 23)
		env->fractal->c.x = env->fractal->c.x - 0.00001;
	else if (key == 22)
		env->fractal->c.x = env->fractal->c.x + 0.00001;
	else if (key == 27 && env->fractal->zoom > 1)
		env->fractal->zoom--;
	else if (key == 24)
		env->fractal->zoom++;
	else
		return (0);
	mlx_clear_window(env->mlx_ptr, env->window);
	return (choose_fractal(env));
}
