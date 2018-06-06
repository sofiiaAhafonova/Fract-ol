/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:25:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 00:25:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	remove_env(t_env *env)
{
	if (!env)
		return ;
	mlx_destroy_image(env->mlx_ptr, env->image.img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->window);
}
