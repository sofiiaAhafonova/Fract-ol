/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:33:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 21:33:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex map_point(double radius, unsigned int zoom, int x, int y)
{
	t_complex c;
	int l;

	l = SCREEN_WIDTH < SCREEN_HEIGHT ? SCREEN_WIDTH : SCREEN_HEIGHT;
	c.x = 2 * radius * (x - SCREEN_WIDTH / 2.0) / (l * zoom);
	c.y = 2 * radius * (y - SCREEN_HEIGHT / 2.0) / (l * zoom);
	return (c);
}

void	each_pixel(t_env *env, int x, int y, t_complex z0)
{
	int			i;
	t_complex	z1;

	i = 0;
	while (++i <= env->fractal->n)
	{
		z1 = add(sqr(z0),env->fractal->c);
		if (mod(z1)>env->fractal->radius)
		{
			mlx_pixel_put(env->mlx_ptr, env->window, x, y, (i << 21) + (i << 10) + i * 8);
			break;
		}
		z0 = z1;
	}
	if (i > env->fractal->n)
		mlx_pixel_put(env->mlx_ptr, env->window, x, y, 0);
}

void	julia_set(t_env *env)
{
	int			x;
	int 		y;
	t_complex	z0;

	x = -1;
	while (++x <= SCREEN_WIDTH)
	{
		y = -1;
		while (++y <= SCREEN_HEIGHT)
		{
			z0 = map_point(env->fractal->radius, env->fractal->zoom, x, y);
			each_pixel(env, x, y, z0);
		}
	}
}