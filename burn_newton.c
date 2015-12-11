/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 21:19:02 by mwilk             #+#    #+#             */
/*   Updated: 2015/12/11 22:51:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burnship(t_data *d, int x, int y, int maxit)
{
	d->u.rc = 1.5 * (x - X_HALF) / d->zoom_w + d->os_x + 0.5;
	d->u.ic = (y - Y_HALF) / d->zoom_h + d->os_y - 0.4;
	d->u.i = 1;
	while (d->u.i < maxit)
	{
		d->u.zxx = d->u.rz * d->u.rz;
		d->u.zyy = d->u.iz * d->u.iz;
		d->u.old_rz = d->u.rz;
		d->u.rz = d->u.rz * d->u.rz - d->u.iz * d->u.iz - d->u.rc;
		d->u.iz = 2 * fabs(d->u.iz * d->u.old_rz) + d->u.ic;
		if (d->u.zxx + d->u.zyy > 4.0)
			break ;
		d->u.i++;
	}
	if (d->u.i >= maxit)
		return (0);
	return (get_img_color(d, d->u.i, maxit));
}

int			newton(t_data *d, int x, int y, int maxit)
{
	d->u.rc = 1.5 * (x - X_HALF) / (d->zoom * X_HALF) + d->os_x;
	d->u.ic = (y - Y_HALF) / (d->zoom * Y_HALF) + d->os_y;
	d->u.rz = d->u.rc;
	d->u.iz = d->u.ic;
	d->u.i = 0;
	while (++d->u.i < maxit)
	{
		d->u.zxx = d->u.rz * d->u.rz;
		d->u.zyy = d->u.iz * d->u.iz;
		d->u.d = 3.0 * ((d->u.zxx - d->u.zyy) * (d->u.zxx - d->u.zyy) +
				4.0 * d->u.zxx * d->u.zyy);
		if (d->u.d == 0.0)
		{
			d->u.d = 0.000001;
			break ;
		}
		d->u.old_rz = d->u.rz;
		d->u.rz = (2.0 / 3.0) * d->u.rz + (d->u.zxx - d->u.zyy) / d->u.d;
		d->u.iz = (2.0 / 3.0) * d->u.iz - 2.0 * d->u.old_rz * d->u.iz / d->u.d;
	}
	if (d->u.rz > 0.0)
		return (RGB(255, 0, 0));
	else if ((d->u.rz < -0.3) && (d->u.iz > 0.0))
		return (RGB(0, 255, 0));
	return (RGB(0, 0, 255));
}
