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
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# define SCREEN_HEIGHT 1000
# define SCREEN_WIDTH 1800
# define ESC 53

typedef enum	e_type
{
	JULIA, MANDELBROT
}				t_type;

typedef struct	s_complex
{
	double x;
	double y;
}				t_complex;

typedef struct	s_fractal
{
	t_type			type;
	t_complex		c;
	double			radius;
	int				n;
	unsigned int	zoom;
	int				(*color_func)(int);

}				t_fractal;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*window;
	t_img		image;
	t_fractal	fractal;

}				t_env;

t_env           *init(char *fractol);
int				init_julia(t_env *env);
void			remove_env(t_env *env);
int				close_window(t_env *env);
int				on_key_press(int key, t_env *env);
t_complex		add(t_complex a, t_complex b);
t_complex		sqr(t_complex a);
double			mod(t_complex a);
void			julia_set(t_env *env);
void			mandelbrot_set(t_env *env);
int 			print_error(char *str);
int				calc_color_julia(int i);

#endif
