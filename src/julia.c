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

t_complex mapPoint(double radius, unsigned  int zoom, int x, int y)
{
	t_complex c;
	int l;

	l = SCREEN_WIDTH < SCREEN_HEIGHT ? SCREEN_WIDTH : SCREEN_HEIGHT;
	c.x = 2 * radius * (x - SCREEN_WIDTH / 2.0) / (l * zoom);
	c.y = 2 * radius * (y - SCREEN_HEIGHT / 2.0) / (l * zoom);
	return (c);
}

void julia_set(t_env *env)
{
	int x,y, i;
	t_complex z0,z1;

	for(x=0;x<=SCREEN_WIDTH;x++)
		for(y=0;y<=SCREEN_HEIGHT;y++){
			z0 = mapPoint(env->fractal->radius, env->fractal->zoom, x, y);
			for(i=1;i<=env->fractal->n;i++){
				z1 = add(sqr(z0),env->fractal->c);
				if(mod(z1)>env->fractal->radius){
					mlx_pixel_put(env->mlx_ptr, env->window, x, y, (i << 21) + (i << 10) + i*8);
					break;
				}
				z0 = z1;
			}
			if(i > env->fractal->n)
				mlx_pixel_put(env->mlx_ptr, env->window, x, y, 0);
		}
}
