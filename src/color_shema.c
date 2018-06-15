/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:06:09 by sahafono          #+#    #+#             */
/*   Updated: 2018/06/15 16:06:10 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		color_schema_one(int i)
{
	return ((i << 21) + (i << 10) + i * 8);
}

int		color_schema_two(int i)
{
	return ((i << 10) + i * 8);
}

int		set_color(int red, int green, int blue)
{
	return (65536 * red + 256 * green + blue);
}

int		color_schema_three(int i)
{
	double t;

	t = (double)i / (double)70;
	return (set_color((int)(9 * (1 - t) * t * t * t * 255),
		(int)(15 * (1 - t) * (1 - t) * t * t * 255),
		(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)));
}

int		change_color_schema(t_env *env)
{
	if (env->fractal.color_schema == 1)
	{
		env->fractal.color_schema = 2;
		env->fractal.color_func = color_schema_two;
	}
	else if (env->fractal.color_schema == 2)
	{
		env->fractal.color_schema = 3;
		env->fractal.color_func = color_schema_three;
	}
	else if (env->fractal.color_schema == 3)
	{
		env->fractal.color_schema = 1;
		env->fractal.color_func = color_schema_one;
	}
	return (0);
}
