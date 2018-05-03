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
#include <stdio.h>
int		close_window(t_env *env)
{
	remove_env(env);
	//system("leaks fractol");
	exit(EXIT_SUCCESS);
}

int		on_key_press(int key, t_env *env)
{
	if (key == ESC || key == ESC_LINUX)
		return (close_window(env));
	else if (key == 49 || key == 50)
		env->julia->radius = key == 49 ? env->julia->radius - 0.1 : env->julia->radius + 0.1;
	else if (key == 51 && env->julia->n > 1)
		env->julia->n--;
	else if (key == 52)
		env->julia->n++;
	else if (key == 54)
		env->julia->radius++;
	else if (key == 55)
		env->julia->radius--;
	else if (key == 56)
		env->julia->c.x = env->julia->c.x - 0.00001;
	else if (key == 57)
		env->julia->c.x = env->julia->c.x + 0.00001;
	else if (key == ZOOM_OUT_KEY_LINUX && env->julia->zoom > 1)
		env->julia->zoom--;
	else if (key == ZOOM_IN_KEY_LINUX)
		env->julia->zoom++;
	else
		return (0);
	mlx_clear_window(env->mlx_ptr, env->window);
	juliaSet(env);
	return (0);
}
