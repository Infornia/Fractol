/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 21:19:02 by mwilk             #+#    #+#             */
/*   Updated: 2015/11/29 11:56:22 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burnship(t_data *d, int x, int y, int maxit)
{
	d->u.RC = 1.5 * (x - X_HALF) / d->zoom_w + d->os_x + 0.5;
	d->u.IC = (y - Y_HALF) / d->zoom_h + d->os_y - 0.4;
	d->u.i = 1;
	while (d->u.i < maxit)
	{
		d->u.zxx = d->u.RZ * d->u.RZ;
		d->u.zyy = d->u.IZ * d->u.IZ;
		d->u.old_RZ = d->u.RZ;
		d->u.RZ = d->u.RZ * d->u.RZ - d->u.IZ * d->u.IZ - d->u.RC;
		d->u.IZ = 2 * fabs(d->u.IZ * d->u.old_RZ) + d->u.IC;
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
	d->u.RC = 1.5 * (x - X_HALF) / (d->zoom * X_HALF) + d->os_x;
	d->u.IC = (y - Y_HALF) / (d->zoom * Y_HALF) + d->os_y;
	d->u.RZ = d->u.RC;
	d->u.IZ = d->u.IC;
	d->u.i = 0;
	while (++d->u.i < maxit)
	{
		d->u.zxx = d->u.RZ * d->u.RZ;
		d->u.zyy = d->u.IZ * d->u.IZ;
		d->u.d = 3.0 * ((d->u.zxx - d->u.zyy) * (d->u.zxx - d->u.zyy) +
				4.0 * d->u.zxx * d->u.zyy);
		if (d->u.d == 0.0)
		{
			d->u.d = 0.000001;
			break ;
		}
		d->u.old_RZ = d->u.RZ;
		d->u.RZ = (2.0 / 3.0) * d->u.RZ + (d->u.zxx - d->u.zyy) / d->u.d;
		d->u.IZ = (2.0 / 3.0) * d->u.IZ - 2.0 * d->u.old_RZ * d->u.IZ / d->u.d;
	}
	if (d->u.RZ > 0.0)
		return (RGB(255, 0, 0));
	else if ((d->u.RZ < -0.3) && (d->u.IZ > 0.0))
		return (RGB(0, 255, 0));
	return (RGB(0, 0, 255));
}
