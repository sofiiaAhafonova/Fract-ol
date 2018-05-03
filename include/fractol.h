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
#include <math.h>
# define SCREEN_HEIGHT 1000
# define SCREEN_WIDTH 1800
# define ESC 53
# define ESC_LINUX 65307
# define ZOOM_IN_KEY 24
# define ZOOM_IN_KEY_LINUX 61
# define ZOOM_OUT_KEY 27
# define ZOOM_OUT_KEY_LINUX 45


typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct	s_julia
{
	t_complex c;
	double radius;
	int n;
	unsigned int zoom;

}				t_julia;
typedef struct	s_env
{
	void *mlx_ptr;
	void *window;
	void *image;
	t_julia *julia;

}				t_env;

t_env	*init(char *fractol);
void	remove_env(t_env *env);
int		close_window(t_env *env);
int		on_key_press(int key, t_env *env);
t_complex add(t_complex a, t_complex b);
t_complex sqr(t_complex a);
double mod(t_complex a);
void juliaSet(t_env *env);

#endif