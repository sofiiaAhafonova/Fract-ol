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

t_env	*init(char *fractol)
{
	t_env *env;

	if ((env = malloc(sizeof(t_env))) == 0)
		return (0);
	if (!(env->mlx_ptr = mlx_init()))
		return (0);
	if (!(env->window = mlx_new_window(env->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, fractol)))
		return (0);
	if (!(env->image = mlx_new_image(env->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT)))
		return (0);
	if (!(env->julia  = (t_julia*)malloc(sizeof(t_julia))))
		return (0);
	env->julia->c.x =-0.7;
	env->julia->c.y = 0.27015;
	env->julia->radius = 2;
	env->julia->n = 150;
	env->julia->zoom = 1;
	return (env);
}