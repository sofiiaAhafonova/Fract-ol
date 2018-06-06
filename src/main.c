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

int 	print_error(char *str)
{
	ft_putstr(str);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env *env;

    if (argc != 2)
        return (print_error("usage: fractol [julia/mandelbrot]\n"));
	if(!(env = init(argv[1])))
        return (print_error("Wrong fractal name\n"));
	mlx_hook(env->window, 17, 1L << 17, &close_window, env);
	mlx_hook(env->window, 2, 5, on_key_press, env);
    if (env->fractal.type == JULIA)
	{
		init_julia(env);
		julia_set(env);
	}

//	t_env env;
//	int		count_w;
//	int		count_h;
//
//	count_h = -1;
//	env.mlx_ptr = mlx_init();
//	env.window = mlx_new_window(env.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, argv[1]);
//	env.image.img_ptr = mlx_new_image(env.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
//	env.image.data = (int *)mlx_get_data_addr(env.image.img_ptr, &env.image.bpp, &env.image.size_l,
//											&env.image.endian);
//
//	while (++count_h < SCREEN_HEIGHT)
//	{
//		count_w = -1;
//		while (++count_w < SCREEN_WIDTH)
//		{
//			if (count_w % 2)
//
//				env.image.data[count_h * SCREEN_WIDTH + count_w] = 0xFFFFFF;
//			else
//				env.image.data[count_h * SCREEN_WIDTH + count_w] = 0;
//		}
//	}
//	mlx_put_image_to_window(env.mlx_ptr, env.window, env.image.img_ptr, 0, 0);
//	mlx_loop(env.mlx_ptr);

    mlx_loop(env->mlx_ptr);
	return (0);
}