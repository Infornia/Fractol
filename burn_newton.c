/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 21:19:02 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/10 18:15:24 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burnship(t_data *d, int x, int y, int maxit)
{
	d->u.cx = 1.5 * (x - X_HALF) / d->zoom_w + d->os_x + 0.5;
	d->u.cy = (y - Y_HALF) / d->zoom_h + d->os_y - 0.4;
	d->u.i = 1;
	while (d->u.i < maxit)
	{
		d->u.zxx = d->u.zx * d->u.zx;
		d->u.zyy = d->u.zy * d->u.zy;
		d->u.old_zx = d->u.zx;
		d->u.zx = d->u.zx * d->u.zx - d->u.zy * d->u.zy - d->u.cx;
		d->u.zy = 2 * fabs(d->u.zy * d->u.old_zx) + d->u.cy;
		if (d->u.zxx + d->u.zyy > 4.0)
			break;
		d->u.i++;
	}
	if (d->u.i >= maxit)
		return (0);
	return (get_img_color(d, d->u.i, maxit));
}

int			newton(t_data *d, int x, int y, int maxit)
{
	d->u.cx = 1.5 * (x - X_HALF) / (d->zoom * X_HALF) + d->os_x;
	d->u.cy = (y - Y_HALF) / (d->zoom * Y_HALF) + d->os_y;
	d->u.zx = d->u.cx;
	d->u.zy = d->u.cy;
	d->u.i = 0;
	while (++d->u.i < maxit)
	{
		d->u.zxx = d->u.zx * d->u.zx;
		d->u.zyy = d->u.zy * d->u.zy;
		d->u.d = 3.0 * ((d->u.zxx - d->u.zyy) * (d->u.zxx - d->u.zyy) +
				4.0 * d->u.zxx * d->u.zyy);
		if (d->u.d == 0.0)
		{
			d->u.d = 0.000001;
			break ;
		}
		d->u.old_zx = d->u.zx;
		d->u.zx = (2.0 / 3.0) * d->u.zx + (d->u.zxx - d->u.zyy) / d->u.d;
		d->u.zy = (2.0 / 3.0) * d->u.zy - 2.0 * d->u.old_zx * d->u.zy / d->u.d;
	}
	if (d->u.zx > 0.0)
		return (RED);
	else if ((d->u.zx < -0.3) && (d->u.zy > 0.0))
		return (GREEN);
	return (BLUE);
}
