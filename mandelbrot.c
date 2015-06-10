/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:15:25 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/10 17:24:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_data *d, int x, int y, int max_i)
{
	double			nu;

	init_mandelbrot(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.old_zx = d->u.zx;
		d->u.zx = d->u.zx * d->u.zx - d->u.zy * d->u.zy;
		d->u.zy = 2 * d->u.old_zx * d->u.zy;
		d->u.zx += d->u.cx;
		d->u.zy += d->u.cy;
		if (d->u.zx * d->u.zx + d->u.zy * d->u.zy > 4.0)
			break ;
	}
	nu = log(log(sqrt(d->u.zx * d->u.zx + d->u.zy * d->u.zy))) / log(2.0);
	nu = d->u.i - nu;
	if (d->u.i >= max_i)
		return (0);
	return (get_img_color(d, nu, max_i));
}
