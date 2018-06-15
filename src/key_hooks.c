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
	if (env->fractal.type == JULIA)
		julia_set(env);
	else if (env->fractal.type == MANDELBROT)
		mandelbrot_set(env);
	else if (env->fractal.type == BURNINGSHIP)
		burningship(env);
	put_legend(env);
	return (0);
}

int		on_key_press(int key, t_env *env)
{
	if (key == ESC)
		return (close_window(env));
	else if (key == 27)
		env->fractal.zoom /= 1.1;
	else if (key == 24)
		env->fractal.zoom *= 1.1;
	else if (key == 18 && env->fractal.n > 1)
		env->fractal.n--;
	else if (key == 19)
		env->fractal.n++;
	else if (key == 4)
		env->show_legend = env->show_legend ? 0 : 1;
	else if (key == RIGHT_ARROW)
		env->offset_x-=5;
	else if (key == LEFT_ARROW)
		env->offset_x+=5;
	else if (key == TOP_ARROW)
		env->offset_y+=5;
	else if (key == BOTTOM_ARROW)
		env->offset_y-=5;
	else if (key == SPACE)
		env->fractal.change_on_move = env->fractal.change_on_move ? 0 : 1;
	else if (key == 21)
		change_color_schema(env);
	else
		return (0);
	mlx_clear_window(env->mlx_ptr, env->window);
	return (choose_fractal(env));
}
