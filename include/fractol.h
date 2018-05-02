/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:11:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 00:11:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libmlx/mlx.h"
# include <stdlib.h>
# define SCREEN_HEIGHT 1000
# define SCREEN_WIDTH 1800
# define ESC 53
# define ESC_LINUX 65307



typedef struct	s_env
{
	void *mlx_ptr;
	void *window;
	void *image;
}				t_env;

t_env	*init(char *fractol);
void	remove_env(t_env *env);
int		close_window(t_env *env);
int		on_key_press(int key, t_env *env);

#endif