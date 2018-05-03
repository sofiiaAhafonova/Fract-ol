/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:32:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/03 22:32:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex sqr(t_complex a)
{
	t_complex c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

double mod(t_complex a)
{
	return (sqrt(a.x*a.x + a.y*a.y));
}
