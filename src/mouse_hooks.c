/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:56:03 by sahafono          #+#    #+#             */
/*   Updated: 2018/06/15 15:56:08 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		on_mouse_click(int b, int x, int y, t_env *env)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return (0);
	if ((b == 4 || b == 5) &&
		(x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT))
	{
		if (b == 4)
			env->fractal.zoom *= 1.1;
		else
			env->fractal.zoom /= 1.1;
	}
	else if (b == 1 && !env->left_button)
	{
		env->tmp_x = x;
		env->tmp_y = y;
		env->left_button = 1;
	}
	mlx_clear_window(env->mlx_ptr, env->window);
	return (choose_fractal(env));
}

int		mouse_up(int b, int x, int y, t_env *env)
{
	if (b == 1 && env->left_button)
	{
		env->tmp_x = x;
		env->tmp_y = y;
		env->left_button = 0;
	}
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if ((e->fractal.change_on_move) && (e->fractal.c.x && e->fractal.c.y)
		&& (x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT))
	{
		e->fractal.c.x += ((double)x - e->mouse_offset_x) / (SCREEN_WIDTH * 2);
		e->fractal.c.y += ((double)y - e->mouse_offset_y) / (SCREEN_HEIGHT * 2);
		e->mouse_offset_x = x;
		e->mouse_offset_y = y;
	}
	if (e->left_button)
	{
		if (x >= e->tmp_x)
			e->offset_x -= (x - e->tmp_x);
		else
			e->offset_x += (e->tmp_x - x);
		if (y >= e->tmp_y)
			e->offset_y -= (y - e->tmp_y);
		else
			e->offset_y += (e->tmp_y - y);
		e->tmp_x = x;
		e->tmp_y = y;
	}
	mlx_clear_window(e->mlx_ptr, e->window);
	return (choose_fractal(e));
}
