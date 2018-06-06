/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:14:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 00:14:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int		init_julia(t_env *env)
{
	env->fractal->c.x = -0.7;
	env->fractal->c.y = 0.27015;
	env->fractal->radius = 2;
	env->fractal->n = 150;
	env->fractal->zoom = 1;
	env->fractal->color_func = calc_color_julia;
	return (0);
}

t_env   *init(char *fractol)
{
    t_env *env;

	if ((ft_strcmp(fractol, "julia") &&
            ft_strcmp(fractol, "mandelbrot")))
		return (0);
	if ((env = malloc(sizeof(t_env))) == 0)
		return (0);
	if (!(env->mlx_ptr = mlx_init()))
		return (0);
	if (!(env->window = mlx_new_window(env->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, fractol)))
		return (0);
	if (!(env->image = mlx_new_image(env->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT)))
		return (0);
	if (!(env->fractal  = (t_fractal*)malloc(sizeof(t_fractal))))
		return (0);
	if (!ft_strcmp(fractol, "julia"))
		env->fractal->type = JULIA;
	else
		env->fractal->type = MANDELBROT;
	return (env);
}