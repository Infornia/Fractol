/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:15:25 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/11 22:51:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_data *d, int x, int y, int max_i)
{
	int			color;

	init_mandelbrot(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.old_rz = d->u.rz;
		d->u.rz = d->u.old_rz * d->u.old_rz - d->u.iz * d->u.iz;
		d->u.iz = 2 * d->u.old_rz * d->u.iz;
		d->u.rz += d->u.rc;
		d->u.iz += d->u.ic;
		if (d->u.rz * d->u.rz + d->u.iz * d->u.iz >= 4.0)
			break ;
	}
	color = d->u.i * 255 * 5 / max_i;
	if (d->u.i >= max_i)
		return (0);
	return (get_img_color(d, d->u.i, max_i));
}

int			mandelbrot_special(t_data *d, int x, int y, int max_i)
{
	double			color;

	init_mandelbrot(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.old_rz = d->u.rz;
		d->u.rz = d->u.old_rz * d->u.old_rz - d->u.iz * d->u.iz;
		d->u.iz = 2 * d->u.old_rz * d->u.iz;
		d->u.rz += d->u.rc;
		d->u.iz += d->u.ic;
		if (d->u.rz * d->u.rz + d->u.iz * d->u.iz >= 4.0)
			break ;
		d->u.i++;
	}
	color = d->u.i + 1 - log(log(d->u.rz + d->u.iz)) / log(2);
	return (get_img_color(d, color, max_i));
}
