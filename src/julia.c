/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:47:34 by sahafono          #+#    #+#             */
/*   Updated: 2018/06/15 16:47:36 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	each_pixel(t_env *env, int x, int y, t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z = add_complex(sqr_complex(c), env->fractal.c);
	while ((z.x * z.x + z.y * z.y) < 4 && ++i <= env->fractal.n)
	{
		z = add_complex(sqr_complex(z), env->fractal.c);
	}
	if (i > env->fractal.n)
		env->image.data[y * SCREEN_WIDTH + x] = 0;
	else
		env->image.data[y * SCREEN_WIDTH + x] = env->fractal.color_func(i);
}

void	julia_set(t_env *env)
{
	int			x;
	int			y;
	t_complex	c;
	int			l;

	y = -1;
	l = SCREEN_WIDTH < SCREEN_HEIGHT ? SCREEN_WIDTH : SCREEN_HEIGHT;
	while (++y <= SCREEN_HEIGHT)
	{
		x = -1;
		while (++x <= SCREEN_WIDTH)
		{
			c.x = 4 * (x + env->offset_x - SCREEN_WIDTH / 2.0) /
					(l * env->fractal.zoom);
			c.y = 4 * (y + env->offset_y - SCREEN_HEIGHT / 2.0) /
					(l * env->fractal.zoom);
			each_pixel(env, x, y, c);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window,
							env->image.img_ptr, 0, 0);
}
