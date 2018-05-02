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
	return (0);
}
