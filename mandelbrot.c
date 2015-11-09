/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:15:25 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/09 19:27:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_data *d, int x, int y, int max_i)
{
	float			nu;
	int			color;

	init_mandelbrot(d, x, y);
	while (++d->u.i < max_i)
	{
		d->u.old_RZ = d->u.RZ;
		d->u.RZ = d->u.old_RZ * d->u.old_RZ - d->u.IZ * d->u.IZ;
		d->u.IZ = 2 * d->u.old_RZ * d->u.IZ;
		d->u.RZ += d->u.RC;
		d->u.IZ += d->u.IC;
		if (d->u.RZ * d->u.RZ + d->u.IZ * d->u.IZ >= 4.0)
			break ;
	}
	nu = log(log(sqrt(d->u.RZ * d->u.RZ + d->u.IZ * d->u.IZ))) / log(2.0);
	nu = d->u.i - nu;
	color =  d->u.i * 255 * 5 / max_i;
	if (d->u.i >= max_i)
		return (0);
	return (get_img_color(d, nu, max_i));
}
