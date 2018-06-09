#include "../include/fractol.h"

int 	on_mouse_move(int x, int y, t_env *env)
{
	env->offset_y = y;
	env->offset_x = x;
	return (0);
}