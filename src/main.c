/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:06:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 00:06:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int		main(int argc, char **argv)
{
	t_env *env;

	if (argc != 2 || !(env = init(argv[1])))
		return (0);
	mlx_hook(env->window, 17, 1L << 17, &close_window, env);
	mlx_hook(env->window, 2, 5, on_key_press, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}